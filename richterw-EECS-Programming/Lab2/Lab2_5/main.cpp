#include <iostream>

using namespace std;

int main()
{
    double xVal;
    double yVal;

    cout << "Enter X Y Pair: " << endl;
    cin >> xVal;
    cout << " ";
    cin >> yVal;

    if ((xVal < 0) && (yVal < 0)) { // X and Y both negative
        cout << "Quadrant is Q3" << endl;
    }
    else if ((xVal < 0) && (yVal > 0)){ // X negative and Y positive
        cout << "Quadrant is Q2" << endl;
    }
    else if ((xVal > 0) && (yVal < 0)){ // X positive and Y negative
        cout << "Quadrant is Q4" << endl;
    }
    else if ((xVal > 0) && (yVal > 0)){ // X and Y both positive
        cout << "Quadrant is Q1" << endl;
    }
    else if ((xVal == 0.0) && (yVal == 0.0)){ // Origin
        cout << "Center Point" << endl;
    }
    else if ((xVal != 0.0) && (yVal == 0.0)){ // X-Axis
        cout << "On X-Axis" << endl;
    }
    else if ((xVal == 0.0) && (yVal != 0.0)){ // Y-Axis
        cout << "On Y-Axis" << endl;
    }
}
