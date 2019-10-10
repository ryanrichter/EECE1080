#include <iostream>

using namespace std;

int main()
{
    int inputNumber = 0;
    double factorial = 1;

    cout << "Enter the number that you wish to know the factorial of: ";
    cin >> inputNumber;

    for (int i = inputNumber; i > 0; i--){
        factorial = factorial * i;
    }
    cout << inputNumber << "! = " << factorial << endl;
}
