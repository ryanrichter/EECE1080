#include <iostream>

using namespace std;

double quadrant = 0;

int whichQuadrant(float x, float y) {
    if ((x < 0) && (y < 0)) { // X and Y both negative
        quadrant = 3;
        return quadrant;
    }
    else if ((x < 0) && (y > 0)){ // X negative and Y positive
        quadrant = 2;
        return quadrant;
    }
    else if ((x > 0) && (y < 0)){ // X positive and Y negative
        quadrant = 4;
        return quadrant;
    }
    else if ((x > 0) && (y > 0)){ // X and Y both positive
        quadrant = 1;
        return quadrant;
    }
    else if ((x == 0.0) && (y == 0.0)){ // Origin
        quadrant = 67;
        return quadrant;
    }
    else if ((x != 0.0) && (y == 0.0)){ // X-Axis
        quadrant = 88;
        return quadrant;
    }
    else if ((x == 0.0) && (y != 0.0)){ // Y-Axis
        quadrant = 89;
        return quadrant;
    }
}


int main()
{
    double xVal;
    double yVal;

    cout << "Enter X Y Pair: " << endl;
    cin >> xVal;
    cout << " ";
    cin >> yVal;

    int quadrantNum = whichQuadrant(xVal, yVal);

    if (quadrantNum == 1) {
        cout << "Quadrant is: Q1" << endl;
    }
    if (quadrantNum == 2) {
        cout << "Quadrant is: Q2" << endl;
    }
    if (quadrantNum == 3) {
        cout << "Quadrant is: Q3" << endl;
    }
    if (quadrantNum == 4) {
        cout << "Quadrant is: Q4" << endl;
    }
    if (quadrantNum == 67) {
        cout << "Center Point" << endl;
    }
    if (quadrantNum == 88) {
        cout << "X-Axis" << endl;
    }
    if (quadrantNum == 89) {
        cout << "Y-Axis" << endl;
    }
}
