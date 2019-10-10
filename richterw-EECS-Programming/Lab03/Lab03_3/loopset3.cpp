#include <iostream>

using namespace std;

int main()
{
    double i = 0;
    double startingIndex = 0;

    cout << "Enter your desired starting point: ";
    cin >> startingIndex;


    for (i = startingIndex;i >= 0;i = i - 0.5) {
        if (i == 0) {
            cout << i;
        }
        else {
            cout << i << ',';
        }
    }
}
