#include <iostream>

using namespace std;

int main()
{
    double scaleNumber;
    cout << "Enter Richter Scale Number: ";
    cin >> scaleNumber;

    if (scaleNumber <= 5.0) {
        cout << endl << "Little Damage" << endl;
    }
    else if ((scaleNumber > 5.0) && (scaleNumber <= 5.5)) {
        cout << endl << "Some Damage" << endl;
    }
    else if ((scaleNumber > 5.5) && (scaleNumber <= 6.5)) {
        cout << endl << "Serious Damage" << endl;
    }
    else if ((scaleNumber > 6.5) && (scaleNumber <= 7.5)) {
        cout << endl << "Disastrous Damage" << endl;
    }
    else if (scaleNumber > 7.5) {
        cout << endl << "Catastrophic Damage" << endl;
    }
}
