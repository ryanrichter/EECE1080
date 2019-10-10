#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Efield(double r, double a = 1){
    double kE = 9*pow(10,9);
    double Q = pow(10,-9);
    if (r < a){
        double eF = (kE * Q * r) / pow(a,3);
        return eF;
    }
    else if (r >= a){
        double eF = (kE * Q) / pow(r,2);
        return eF;
    }
}

int main()
{
    double r;
    double a;

    cout << "Enter r: ";
    cin >> r;
    cout << endl;

    cout << "Enter a: ";
    cin >> a;
    cout << endl;

    cout << "Efield: " << Efield(r,a) << endl;
}
