#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double launchVelocity;
    double time = 0;
    double height = 0;
    cout << "Enter Launch Velocity: ";
    cin >> launchVelocity;

    cout << setw(4) << "Time" << setw(6) << "Height" << endl;
    do {
        height = (launchVelocity * time) - (0.5 * 9.8 * (pow(time,2.0)));
        if (height == 0 && time == 0){
            cout << setw(4) << time << setw(6) << height << endl;
        }
        else if (height <= 0 && time != 0){
            height = 0;
            cout << setw(4) << time << setw(6) << height << endl;
            break;
        }
        else {
            cout << setw(4) << time << setw(6) << height << endl;
        }
        time += 1;
    } while (height >= 0);

}
