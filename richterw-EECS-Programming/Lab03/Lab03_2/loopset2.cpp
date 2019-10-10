#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    double sum = 0;
    double avgCount = 0;
    double average = 0;
    int startingIndex = 0;
    int endingIndex = 0;
    int stepCount = 0;

    cout << "Enter your desired starting index: ";
    cin >> startingIndex;
    cout << endl;
    cout << "Enter your desired ending index: ";
    cin >> endingIndex;
    cout << endl;
    cout << "Enter your desired step count: ";
    cin >> stepCount;


    for (i = startingIndex;i <= endingIndex;i = i + stepCount) {
        sum = sum + i;
        avgCount += 1;
    }
    average = sum / avgCount;
    cout << "SUM: " << sum << endl;
    cout << "AVERAGE: " << average << endl;
}
