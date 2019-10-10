#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double hours;
    double minutes;
    double totalTime;
    double freezerTemp;

    cout << "Enter Hours: ";
    cin >> hours;
    cout << endl;
    cout << "Enter Minutes: ";
    cin >> minutes;
    cout << endl;

    totalTime = hours + (minutes / 60);

    freezerTemp = (4 * pow(totalTime,2)) / (totalTime + 2) - 20;

    cout << "Approximate Temperature: " << freezerTemp << endl;

    return 0;
}
