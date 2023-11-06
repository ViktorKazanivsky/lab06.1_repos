#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 21;

int RandomNumberGeneration(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void GenerateArray(int array[], int min, int max, int index = 0) {
    if (index < ARRAY_SIZE) {
        array[index] = RandomNumberGeneration(min, max);
        GenerateArray(array, min, max, index + 1);
    }
}

void Print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << array[i] << " ";
    }
    cout << endl;
}

void SummingAndCount(const int array[], int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] % 2 != 0 && i % 13 != 0) {
            count++;
            sum += array[i];
        }
    }
}

void ReplaceElementsWithZeros(int array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] % 2 == 0 || i % 13 == 0) {
            array[i] = 0;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int Array[ARRAY_SIZE];
    GenerateArray(Array, 15, 85);

    cout << "Unmodified Array:" << endl;
    Print(Array, ARRAY_SIZE);

    int count = 0;
    int sum = 0;

    SummingAndCount(Array, count, sum);

    cout << "Count of correct elements: " << count << endl;
    cout << "Sum of correct elements: " << sum << endl;

    ReplaceElementsWithZeros(Array);

    cout << "Modified Array:" << endl;
    Print(Array, ARRAY_SIZE);

    return 0;
}