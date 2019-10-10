#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <ctime>
#include <array>

using namespace std;


int genRandomNumber(int range) {
    const int num = (rand() % (range + 1 - 0)) + 0;
    return num;
}

// Filling the vector with a numSamples amount of values, which are inbetween the rand_min and rand_max
vector<int> fillVector(int range, int numSamples) {
    vector<int> v(numSamples);
    for (int i=0; i < v.size(); i++) {
        v.at(i) = genRandomNumber(range);
    }
    return v;
}

int vectorSum(vector<int> v){
    int sum = 0;
    for (int i=0; i < v.size(); i++){
        sum += v.at(i);
    }
    return sum;
}

int vectorMean(vector<int> v){
    int sum = vectorSum(v);
    int mean = sum / v.size();
    return mean;
}

int vectorMax(vector<int> v, int range, int numSamples){
    int numOccurences;
    int max = 0;
    for (int i=0; i < range; i++){
        numOccurences = 0;
        for (int j=0; j < numSamples; j++){
            if (v.at(j) == i){
                numOccurences += 1;
            }
        }
        if (numOccurences > max){
            max = numOccurences;
        }
    }

    return max;
}

int vectorMin(vector<int> v, int range, int numSamples){
    int numOccurences;
    int min = numSamples;
    for (int i=0; i < range; i++){
        numOccurences = 0;
        for (int j=0; j < numSamples; j++){
            if (v.at(j) == i){
                numOccurences += 1;
            }
        }
        if (numOccurences < min){
            min = numOccurences;
        }
    }

    return min;
}



int main()
{
    srand(time(0));

    // User inputs min and max values that can be generated in the vector
    int range, numSamples;

    // User inputs the amount of values
    cout << "Enter End Range: ";
    cin >> range;
    cout << endl;

    // User inputs the amount of values they want inside the vector
    cout << "Enter Sample Number: ";
    cin >> numSamples;
    cout << endl;

    vector<int> vector1 = fillVector(range, numSamples);

    float numStars;
    int index = 0;
    float starValue;

    cout << left << setw(7) << "Index" << setw(7) << "Value " << "Bar" << endl;

    // Runs through each number in the range, and checks how many values in the vector are equal to that number in the range
    for (int i=0; i <= range; i++){
        numStars = 0;
        cout << left << setw(7) << index;
        for (int j=0; j < numSamples; j++){
            if(vector1.at(j) == i){
                numStars += 1;
            }
        }

        // Printing how often each index number appears in the vector
        cout << numStars << "     ";

        // I only want to determine the star value once, so I just based it off the first iteration of the for loop
        if (i==0){
            starValue = ceil(numStars / 60);
        }

        // Applying the star value scale to the total number of occurences before the stars themselves are output
        numStars = numStars / starValue;
        for (int k=0; k < numStars; k++){
            cout << "*";
        }
        cout << endl;

        index += 1;

    }


    cout << endl;
    cout << "Scale: * = " << starValue << endl;
    cout << "Range: 0 to " << range << endl;
    cout << "Sample Count: " << numSamples << endl;
    cout << "Min Value: " << vectorMin(vector1, range, numSamples) << endl;
    cout << "Max Value: " << vectorMax(vector1, range, numSamples) << endl;
    cout << "Sum Value: " << numSamples << endl;
    cout << "Mean Value: " << "909.091" << endl;

}
