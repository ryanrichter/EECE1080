#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int rollDie() {
    int result = rand() % 6 + 1;
    return result;
}

bool playOneGame(int pointer) {
    srand(time(0));
    int plays = 0;
    int win = 0;

    while (plays < 3){
        int diceRollResult = rollDie();
        if (pointer == diceRollResult){
            cout << "Roll #" << plays+1 << " is " << pointer << endl;
            win = true;
            break;
        }
        else {
            cout << "Roll #" << plays+1 << " is " << diceRollResult << endl;
            win = false;
        }
        plays += 1;
    }
    return win;
}

double winPercentage(double wins, double totalGames) {
    double winPercentage = (wins / totalGames)*100;
    return winPercentage;
}

int newBalance(int wager, int balance, bool win){
    int newBalance;
    if (win == true){
        newBalance = balance + wager;
    }
    else {
        newBalance = balance - wager;
    }
    return newBalance;
}

string thankPlayer(){
    string endString = "Thanks for playing!";
    return endString;
}



int main()
{
    int pointer;
    int wins = 0;
    int totalGames = 0;
    int balance = 100;
    bool win;
    int wager = 0;

    while (balance > 0) {
        cout << "Current Balance: $" << balance << endl;
        cout << "Enter wager (0 to exit): $";
        cin >> wager;
        cout << endl;

        if ((wager <= balance) && !(wager < 0)) {
            if (wager != 0) {
                cout << "Enter your guess (1-6): ";
                cin >> pointer;
                if (pointer <= 6 && pointer >= 1){
                win = playOneGame(pointer);
                if (win == true) {
                    cout << "** WIN **" << endl;
                    wins += 1;
                    totalGames += 1;
                }
                else {
                    cout << "** LOSE **" << endl << endl;
                    totalGames += 1;
                    }
                }
                else {
                    cout << "Pointer must be between 1 and 6." << endl << endl;
                }
            }
            else {
                cout << "Final balance: " << balance << endl;
                cout << "You won " << wins << " times out of " << totalGames << " games for a win percentage of " << winPercentage(wins,totalGames) << "%" << endl;
                cout << thankPlayer() << endl;
                return 0;
            }
        }
        else {
            cout << "Wager must be positive and less than your current balance." << endl << endl;
        }
        balance = newBalance(wager, balance, win);
    }
    cout << "You ran out of money!" << endl;
    cout << "You played " << totalGames << " games and won " << wins << " of them." << endl;
    cout << "Your win percentage is " << winPercentage(wins,totalGames) << "%" << endl;
    cout << thankPlayer() << endl;
}


