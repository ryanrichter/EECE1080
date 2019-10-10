#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double stdWidth = 0;
    double tolerance = 0;
    int temp = 60;
    double size = 0;

    cout << "Enter the standard width: ";
    cin >> stdWidth;
    cout << endl;
    cout << "Enter the tolerance: ";
    cin >> tolerance;
    cout << endl;

    cout << fixed << setw(1) << "Temperature" << setw(10) << "Width" << setw(20) << "Within Tolerance" << endl;
    do {
        size = stdWidth + (temp - 70) * (0.0001);
        if (size > (stdWidth - tolerance) && size < (stdWidth + tolerance)){
            cout << fixed << setw(5) << temp;
            cout << fixed << setw(15) << setprecision(7) << size << setw(15) << "*" << endl;
        }
        else {
            cout << fixed << setw(5) << temp;
            cout << fixed << setw(15) << setprecision(7) << size << endl;
        }

        temp += 1;

    } while(temp >= 60 && temp <=85);

}
