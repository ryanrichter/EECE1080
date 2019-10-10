#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a;
    double b;
    double c;
    double d;
    double formula1;
    double formula2;
    double formula3;

    cout << "Enter Four numbers: ";
    cin >> a;
    cout << " ";
    cin >> b;
    cout << " ";
    cin >> c;
    cout << " ";
    cin >> d;
    cout << " ";

    formula1 = (a + b + c) / (2 * a * c);
    formula2 = (pow(a,2)) / b + (c / d) * (a + b);
    formula3 = (pow(a,(2 + b + c))) + a - c + 4;

    cout << "Formula 1: " << formula1 << endl;
    cout << "Formula 2: " << formula2 << endl;
    cout << "Formula 3: " << formula3 << endl;
}
