#include <iostream>
#include <cmath>

using namespace std;

// Constant for tolerance
const double TOLERANCE = 0.001;

// Function prototype
double newtonRoot(double);
double f(double);
double fprime(double);

//Driver method main
int main() {
    cout.precision(4);
    cout.setf(ios::fixed);

    // Prompt the user for initial guess
    double iGuess;

    // Loop through until user wants
    char choice;
    do {
        cout << "Enter Guess: ";
        cin >> iGuess;

        // Call for the function newtonRoot
        double root = newtonRoot(iGuess);

        // Print the root
        cout << "Root: " << root << endl;

        cout << "Enter Another Guess y/n? ";
        cin >> choice;
    }while (choice=='y'||choice=='Y');

    return 0;
}

//Function definition for newton raphson
double newtonRoot(double x) {
    // Calculate the step size
    double h = f(x)/fprime(x);

    // Loop through the values
    while(fabs(h) >= TOLERANCE) {
        // Update the step size
        h = f(x)/fprime(x);

        // Update the current root
        x = x-h;

        // Print the current root
        cout<<"The value of current root is: "<<x<<endl;
    }

    // Return the root
    return x;
}


// Function definition for f(x)
double f(double x){
    return (pow(x, 4) + (2*pow(x, 3)) - (31*pow(x, 2)) - (32*x) + 60);
}

// Function definition for f'(x)
double fprime(double x){
    return ((4*pow(x, 3)) + (6*pow(x, 2)) - (62*x) - 32);
}
