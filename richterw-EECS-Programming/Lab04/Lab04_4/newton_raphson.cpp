#include <iostream>
#include <cmath>

using namespace std;

const double TOLERANCE = 0.001;

double newtonRoot(double);
double f(double);
double fprime(double);

int main() {
    cout.precision(4);
    cout.setf(ios::fixed);

    double iGuess;

    char choice;
    do {
        cout << "Enter Guess: ";
        cin >> iGuess;

        double root = newtonRoot(iGuess);

        cout << "Root: " << root << endl;

        cout << "Enter Another Guess: y/n? ";
        cin >> choice;
    }while (choice=='y'||choice=='Y');

    return 0;
}

double newtonRoot(double x) {

    double h = f(x)/fprime(x);

    while(fabs(h) >= TOLERANCE) {

        h = f(x)/fprime(x);

        x = x-h;

        cout<<"The value of current root is: "<<x<<endl;
    }
    return x;
}


double f(double x){
    return (pow(x, 4) + (2*pow(x, 3)) - (31*pow(x, 2)) - (32*x) + 60);
}

double fprime(double x){
    return ((4*pow(x, 3)) + (6*pow(x, 2)) - (62*x) - 32);
}
