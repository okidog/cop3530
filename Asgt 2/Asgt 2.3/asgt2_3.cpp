#include <iostream>
using namespace std;

void readInput(int& length, int array[]) {
    cout << "Enter the length of the array:" << endl;
    cin >> length;
    for (int i = 0; i < length; i++) {
        cout << "Enter array item " << i+1 << ":" << endl;
        cin >> array[i];
    }
}

void twoLargest(int& length, int array[]) {
    int large1 = 0;
    int large2 = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > large1) {
            large2 = large1;
            large1 = array[i];
        } else if (large2 < array[i]) {
            large2 = array[i];
        }
    }
    cout << "The two largest numbers in the list are: " << large1 << ' ' << large2;
}

int main() {
    int length = 0;
    int array[99] = {0};
    readInput(length, array);
    twoLargest(length, array);
    return 0;
};