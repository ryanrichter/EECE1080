#include <iostream>

using namespace std;

bool compareDelta(double num1, double num2, double delta) {
    double difference = num1-num2;
    if (difference > delta) {
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    double Number1 = 0;
    double Number2 = 0;
    double delta = 0;
    cout << "Please enter Number 1: ";
    cin >> Number1;
    cout << endl;
    cout << "Please enter Number 2: ";
    cin >> Number2;
    cout << endl;
    cout << "Please enter delta value: ";
    cin >> delta;
    cout << endl;

    bool boolResult = compareDelta(Number1, Number2, delta);
    cout << "Result: " << boolResult;
}
