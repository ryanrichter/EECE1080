#include <iostream>

using namespace std;

int main()
{
    float enteredNumber = 0.0;
    float sum = 0.0;

    do {
        cout << "Enter Positive Number to Add or Enter Zero or Negative Number to End: ";
        cin >> enteredNumber;
        if (enteredNumber > 0) {
            sum+=enteredNumber;
        }

    } while(enteredNumber > 0);

    cout << "Sum of Entered Numbers: ";
    cout << sum;
    cout << endl;
}
