/*
 * Project Title:
 * - Battleship
 * Description: A simple text/GUI based Battleship game. Cycles through the players in order to simulate the actual Battleship game experience. A 2 player game.
 * This program prompts each player for placement of their ships, and then takes turns cycling through turns for the players until one player's ships have been sunk.
 *
 * Developers:
 * - Ryan Richter - richterw@mail.uc.edu
 * - Blake Sauerwein - sauerwba@mail.uc.edu
 *
 * Help Received:
 * - Instructors - Ade Alabi, Robert Montjoy
 *
 *
 * Developer comments:
 * Developer 1: Ryan Richter
 * I did most of the object-oriented programming for this project. I implemented the classes and their functionality throughout the program. Also, the grid drawing function was done mostly
 * by me.
 *
 * Developer 2: Blake Sauerwein
 * I developed and implemented most of the functions throughout the program, aside from the DrawBoard() function. I also wrote the main() section of the program in which the game itself is
 * run.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

// Character representations of the game pieces
const char waterChar = '~';
const char hitChar = 'X';
const char shipChar = 'S';
const char missChar = '0';

// Width and length of the game board
const int gameBoard_width = 9;
const int gameBoard_height = 9;

const int ship_types = 5;



struct PLAYER {
    char grid[gameBoard_width][gameBoard_height];
} player[3]; // Just using players 1 & 2, not 0

struct POINT {
    //A location on the grid defined
    //by X(horizontal) Y(vertical) coordinates
    int X;
    int Y;
};

struct SHIP {
    //Ship name
    string name;

    //Total space taken up on the grid
    int length;

    //Coordinates of these spaces
    POINT onGrid[5]; // 4 is the max length, 0-4

    // Whether or not those coordinates have been "hit"
    bool hitFlag[5];

} ship[ship_types];

enum DIRECTION {HORIZONTAL,VERTICAL}; // Needed for placing ships, horizontal and vertical directions

struct PLACESHIPS { // Class for ship placement, features direction and type of ship
    DIRECTION direction;
    SHIP shipType;
};

bool gameRunning = false;

//Functions
void LoadShips();

void ClearBoard();
void DrawBoard(int);

PLACESHIPS InputUserShipPlacement();

bool UserAttackInput(int&,int&,int);

bool GameOver(int);


/* Function Name: DrawBoard()
 *
 * Function Description:
 * This function draws the game board for each player when it is their placement turn / their attack turn.
 * (NOTE: When it is Player 1's attack turn, Player 2's board will be drawn as Player 1 makes his attacking
 *  move based on the board of Player 2)
 *
 * Parameters:
 * thisPlayer - The player number whose board should be drawn
 *
 * return value:
 * Void function - no return value
 */
void DrawBoard(int thisPlayer)
{
    // Draws the board for the player identified by thisPlayer
    cout << "Player " << thisPlayer << "'s Board\n";

    // Loop through top row and columns
    cout << "   ";
    for (int w = 1; w < gameBoard_width; ++w) {
        if (w < 10)
            // If numbers are 1 character long, add two spaces after
            cout << w << "  ";
        else if (w >= 10)
            // If numbers are 2 characters long, add one space after
            cout << w << " ";
    }
    cout << "\n";

    // Cycle through every grid point and display it
    for (int h = 1; h < gameBoard_height; ++h){
        for (int w = 1; w < gameBoard_width; ++w){

            // If this is the first, leftmost grid point, number the grid first
            if (w==1) cout << h << " ";

            // If h is 1 character long, add an extra space to keep numbers lined up
            if (w<10 && w==1) cout << " ";

            // Display grid contents
            if (gameRunning == false) cout << player[thisPlayer].grid[w][h] << "  ";

            // Don't show the ships themselves, but display the hitChar if the ship has been hit
            if (gameRunning == true && player[thisPlayer].grid[w][h] != shipChar)
            {cout << player[thisPlayer].grid[w][h] << "  ";}
            else if (gameRunning == true && player[thisPlayer].grid[w][h] == shipChar)
            {cout << waterChar << "  ";}

            // If the end of the board is reached, next line
            if (w == gameBoard_width-1) cout << "\n";
        }
    }
}


/* Function Name: LoadShips()
 *
 * Function Description:
 * This function loads each ship that the players are to place on their game boards. Each have different lengths and names.
 *
 * Parameters:
 * No parameters
 *
 * return value:
 * Void function - no return value
 */

void LoadShips()
{
    // Sets length values for the ships to be placed by the player
    ship[0].name = "Cruiser"; ship[0].length = 2;
    ship[1].name = "Frigate"; ship[1].length = 3;
    ship[2].name = "Submarine"; ship[2].length = 3;
    ship[3].name = "Escort"; ship[3].length = 4;
    ship[4].name = "Battleship"; ship[4].length = 5;
}


/* Function Name: InputUserShipPlacement()
 *
 * Function Description:
 * This function acceses the class PLACESHIPS, which contains the direction of the ship to be placed (vertical, horizontal) and the ship type (name, length). It checks agains the tmp value
 * to make sure that the data entered is acceptable input for the boundaries of the game board.
 *
 * Parameters:
 * No parameters
 *
 * return value:
 * returns tmp value, which provides the necessary data required for the program to be able to place the ships.
 */

PLACESHIPS InputUserShipPlacement()
{
    int d, x, y;
    PLACESHIPS tmp;

    // Using this as a bad return
    tmp.shipType.onGrid[0].X = -1;

    // Get 3 integers from user
    cin >> d >> x >> y;
    if (d!=0 && d!=1) return tmp;
    if (x<0 || x>=gameBoard_width) return tmp;
    if (y<0 || y>=gameBoard_height) return tmp;

    // Good data
    tmp.direction = (DIRECTION)d;
    tmp.shipType.onGrid[0].X = x;
    tmp.shipType.onGrid[0].Y = y;
    return tmp;
}


/* Function Name: UserAttackInput()
 *
 * Function Description:
 * This function takes coordinates from the player whose turn it is to attack, and makes sure that the coordinates are acceptable before "attacking".
 *
 * Parameters:
 * x - the x coordinate to be attacked
 * y - the y coordinate to be attacked
 * theplayer - the player whose turn it is, so that the game knows whose board to "attack"
 *
 * return value:
 * goodInput - a bool value that indicates whether the coordinates are within the boundaries of the game board (because you cannot attack outside the game board).
 */
bool UserAttackInput(int& x, int& y, int theplayer)
{
    cout << "\nPlayer " << theplayer << ", coordinates to attack: ";
    bool goodInput = false;
    cin >> x >> y;
    if (x < 0 || x >= gameBoard_width) return goodInput;
    if (y < 0 || y >= gameBoard_height) return goodInput;
    goodInput = true;
    return goodInput;
}


/* Function Name: ClearBoard()
 *
 * Function Description:
 * This function cycles through each player and sets each character in the game board grid equal to the water character "~"
 *
 * Parameters:
 * No parameters
 *
 * return value:
 * Void function - no return value
 */

void ClearBoard()
{
    // Loop through each player
    for (int plyr=1; plyr<3; ++plyr)
    {
        // For each grid point, set the space equal to the water character
        for (int w = 0; w < gameBoard_width; ++w){
            for (int h = 0; h < gameBoard_height; ++h){
                player[plyr].grid[w][h] = waterChar;
            }
        }
    }
}


/* Function Name: GameOver()
 *
 * Function Description:
 * This function checks if the enemy player's ships are sunk, and sets a bool value as true or false based on this result
 *
 * Parameters:
 * enemyPlayer - The player's board to be checked.
 * (NOTE: The "enemy" is defined as the player whose turn it is NOT. This function checks the board of the "enemy" who is a different player each turn)
 *
 * return value:
 * hasWon - A bool value that indicates whether or not the enemy has ships remaining, if so, hasWon is true and the game is over (see main()).
 */

bool GameOver(int enemyPlayer)
{
    bool hasWon = true;

    // Search enemy board
    for (int w = 0; w < gameBoard_width; ++w){
            for (int h = 0; h < gameBoard_height; ++h){

                // If any ships remain, game is not over
                if (player[enemyPlayer].grid[w][h] = shipChar){
                        hasWon = false;
                        return hasWon;
                    }
            }
    }
    // If this is reached, someone has won
    return hasWon;
}


int main()
{
    LoadShips();
    ClearBoard();

    // Starting phase of game, ships placed
    // Loop through player 1 and 2
    for (int playerNum=1; playerNum<3; ++playerNum)
    {
        //Loop through each ship type to place
        for (int shipType=0; shipType<ship_types; ++shipType) // For each ship type...
        {
            // Display board for player
            system("cls");
            DrawBoard(playerNum);
            // Display instructions
            cout << endl;
            cout << "Instructions (Player " << playerNum << ")\n\n";
            cout << "Ship placement phase. This is the format:\n";
            cout << "Facing (0:Horizontal,1:Vertical), X (top-row) coordinates, Y (left-side) coordinates\n";
            cout << "Ex: 1 1 1    This would place a ship beginning at X:1 Y:1 going vertical\n\n";
            cout << "On deck: " << ship[shipType].name << " which is " << ship[shipType].length  << " spaces long\n";
            cout << "Where do you want it placed? ";

            // Get input but make sure it is good input
            PLACESHIPS aShip;
            aShip.shipType.onGrid[0].X = -1;
            while (aShip.shipType.onGrid[0].X == -1)
            {
                aShip = InputUserShipPlacement();
            }

            // Combine user data with "this ship" data
            aShip.shipType.length = ship[shipType].length;
            aShip.shipType.name = ship[shipType].name;

            // Add the first grid point to the player's game board based on their input
            player[playerNum].grid[aShip.shipType.onGrid[0].X][aShip.shipType.onGrid[0].Y] = shipChar;

            // Determine all grid points based on length and direction input by the player
            for (int i=1; i<aShip.shipType.length; ++i)
            {
                if (aShip.direction == HORIZONTAL){
                    aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i-1].X+1;
                    aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i-1].Y; }
                if (aShip.direction == VERTICAL){
                    aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i-1].Y+1;
                    aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i-1].X; }

                // Add the REMAINING grid points to our current players game board
                player[playerNum].grid[aShip.shipType.onGrid[i].X][aShip.shipType.onGrid[i].Y] = shipChar;
            }
            // Loop through each ship type
        }
        // Loop through each player
    }

    // Now begin the game
    gameRunning = true;
    int thisPlayer = 1;
    do {
        // It is player 1's turn, so the
        // opposite player's board is displayed
        int enemyPlayer;
        if (thisPlayer == 1) enemyPlayer = 2;
        if (thisPlayer == 2) enemyPlayer = 1;
        system("cls");
        DrawBoard(enemyPlayer); // Draw the enemy player's board based on whose turn it is

        // Get attack coord inputs from this player
        bool goodInput = false;
        int x,y;
        while (goodInput == false) {
            goodInput = UserAttackInput(x,y,thisPlayer);
        }

        // Check the board at the given coordinates; if a ship is there, set as hit(X), otherwise it is a miss(0)
        if (player[enemyPlayer].grid[x][y] == shipChar){
            player[enemyPlayer].grid[x][y] = hitChar;
        }
        if (player[enemyPlayer].grid[x][y] == waterChar){
            player[enemyPlayer].grid[x][y] = missChar;
        }

        // Call function that checks if the game is over
        // No one has won if false (0) is returned
        int aWin = GameOver(enemyPlayer);
        if (aWin != 0) {
            gameRunning = false;
            break;
        }
        // Alternate between each player as we loop back around
        thisPlayer = (thisPlayer == 1) ? 2 : 1;
    } while (gameRunning);

    system("cls");
    cout << "\n\nGame Over! Player " << thisPlayer << " has won!\n\n\n\n";

    system("pause");
    return 0;
}
