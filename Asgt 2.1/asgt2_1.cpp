#include <iostream>
using namespace std;

void selectionSort(int array[], int& length) {
    int maxIndex = 0;
    int swapTemp = 0;
    for (int i = 0; i <= length-2; i++) {
        maxIndex = i;
        for (int j = i+1; j <= length-i; j++) {
            if (array[j] > array[maxIndex]) {
                maxIndex = j;
            }
        }
        swapTemp = array[i];
        array[i] = array[maxIndex];
        array[maxIndex] = swapTemp;
    }
}

void readInput(int& length, int array[]) {
    cout << "Enter the length of the array:" << endl;
    cin >> length;
    for (int i = 0; i < length; i++) {
        cout << "Enter array item " << i+1 << ":" << endl;
        cin >> array[i];
    }
}

void output(int array[], int& length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[99] = {0};
    int length = 0;
    readInput(length, array);
    cout << "The original array is: " << endl;
    output(array, length);
    selectionSort(array, length);
    cout << "The sorted array is: " << endl;
    output(array, length);

    return 0;
}
