#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double launchVelocity;
    double time = 0;
    double height = 0;
    double max_height = 0;
    double max_time = 0;
    cout << "Enter Launch Velocity: ";
    cin >> launchVelocity;

    cout << setw(4) << "Time" << setw(6) << "Height" << endl;
    do {
        height = (launchVelocity * time) - (0.5 * 9.8 * (pow(time,2.0)));

        if (launchVelocity == 0) {
            time = 0;
            height = 0;
            cout << setw(4) << time << setw(6) << height << endl;
            break;
        }
        else if (height == 0 && time == 0){
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

        if (height > max_height){
            max_height = height;
            max_time = time;
        }

        time += 1;
    } while (height >= 0);

    cout << "Total Time: " << time << "-seconds" << endl;
    cout << "Maximum Height: " << max_height << " @ " << max_time << "-seconds";

}
