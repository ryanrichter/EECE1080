#include <iostream>
#include <cmath>

using namespace std;

bool compareDelta(double n1, double n2, double delta) {
    double diff = abs(n2 - n1);
    if (diff <= delta && diff >= (delta * -1)) {
        return true;
    }
    return false;
}

int main(void){
    double n1, n2, delta;
    cout << "Number1: ";
    cin >> n1;
    cout << "Number2: ";
    cin >> n2;
    cout << "Delta: ";
    cin >> delta;

    if (compareDelta(n1, n2, delta)) {
        cout << "This set of numbers would return a true." << endl;
    }
    else {
        cout << "This set of numbers would return a false." << endl;
    }
    return 0;
}
