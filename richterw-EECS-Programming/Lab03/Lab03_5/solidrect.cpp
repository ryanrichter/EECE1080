#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned int width = 0;
    unsigned int height = 0;

    cout << "Enter your desired width: ";
    cin >> width;
    cout << "Enter your desired height: ";
    cin >> height;

    for (int i = 0; i < height; i++){
        cout << string(width, '*') << endl;
    }
}
