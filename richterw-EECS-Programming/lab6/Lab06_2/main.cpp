#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

struct player {
    unsigned char x;
    unsigned char y;
};

struct enemy {
    unsigned char x;
    unsigned char y;
};

int random(int n) {
    return rand() % n;
}


int main() {
    cout << "Elon Musk" << endl;
    bool player_win = false;
    int l;

    srand(time(NULL));

    unsigned char board[15][15] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    player player;
    player.x = 1;
    player.y = 1;

    enemy elon;
    elon.x = 6;
    elon.y = 2;



    char tile = 0;
    while(tile != 'q') {
        if (player_win = true) {
                for(int y = 0; y < 15; y ++) {
                    cout << endl;
                    for(int x = 0; x < 15; x++) {
                        // Assigning characters to the numbers in the array. 0 = regular tile, 1 = border, 4 = roadster, 5 = pinto, 6 = yugo
                        if(x == player.x && y == player.y) {
                            cout << (unsigned char)'P';
                        } else if(x == elon.x && y == elon.y) {
                            cout << (unsigned char)'.';
                        } else if(board[y][x] == 1) {
                            cout << (unsigned char)'#';
                        } else if(board[y][x] == 0) {
                            cout << (unsigned char)'.';
                        } else if(board[y][x] == 4) {
                            cout << (unsigned char)'.';
                        } else if(board[y][x] == 5) {
                            cout << (unsigned char)'.';
                        } else if(board[y][x] == 6) {
                            cout << (unsigned char)'.';
                        }
                        player_win = false;
                    }
                }
            }

        cout << endl;

        cout << "To move upwards press 'W', left 'A', down 'S', right 'D': ";
        cin >> tile;


        // Allowing the player's input to actually move the "P" character without it moving outside the bounds
        if(tile == 's' && player.y < 14 && board[player.y + 1][player.x] != 1) {
            player.y++; system("cls");
        }
        if(tile == 'w' && player.y > 0 && board[player.y - 1][player.x] != 1) {
            player.y--; system("cls");
        }
        if(tile == 'a' && player.x > 0 && board[player.y][player.x - 1] != 1) {
            player.x--; system("cls");
        }
        if(tile == 'd' && player.x < 14 && board[player.y][player.x + 1] != 1) {
            player.x++; system("cls");
        }

        // If the player comes across the same tile as Elon, game over
        if (board[player.y] == board[elon.y] && board[player.x] == board[elon.x]) {
            cout << "You've been found by Elon. You are now the Star Man. GAME OVER." << endl;
            system("PAUSE");
            exit(1);
        }

        // If the player finds the roadster tile
        if(board[player.y][player.x] == 4) {
            cout << "You sped off in the Roadster! Good job! " << endl;
            system("PAUSE");
            exit(1);
        }

        // If the player finds the pinto tile
        if(board[player.y][player.x] == 5) {
            cout << "You started the Ford Pinto! The loud noise woke up Elon! Hurry! " << endl;
            system("PAUSE");
        }

        // If the player finds the yugo tile
        if(board[player.y][player.x] == 6) {
            cout << "You started the Yugo! The loud noise woke up Elon! Hurry! " << endl;
            system("PAUSE");
        }

        // Allows Elon to move randomly once he is awoken
        l = random(4) + 1;

        if(l == 1 && board[elon.y + 1][elon.x] != 1) {
            elon.y++; system("cls");
        }
        if(l == 2 && board[elon.y - 1][elon.x] != 1) {
            elon.y--; system("cls");
        }
        if(l == 3 && board[elon.y][elon.x - 1] != 1) {
            elon.x--; system("cls");
        }
        if(l == 4 && board[elon.y][elon.x + 1] != 1) {
            elon.x++; system("cls");
        }
    }


    return 0;
}
