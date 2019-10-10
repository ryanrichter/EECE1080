#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    double sum = 0;
    double avgCount = 0;
    double average = 0;
    for (i=2;i<=35;i = i+3) {
        sum = sum + i;
        avgCount += 1;
    }
    average = sum / avgCount;
    cout << "SUM: " << sum << endl;
    cout << "AVERAGE: " << average;
}
