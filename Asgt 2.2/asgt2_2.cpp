#include <iostream>
using namespace std;

void readInput(int& int1, int& int2) {
        cout << "Enter the 1st integer: " << endl;
        cin >> int1;
        cout << "Enter the 2nd integer: " << endl;
        cin >> int2;
    }
    void EEA(int a, int b) {
         int r = b;
         int oldR = a;
         int q = 0;
         int tempR = 0;
         while (r != 0) {
             q = oldR / r;
             tempR = r;
             r = oldR - q * r;
             oldR = tempR;
         }
         cout << "The GCD is equal to: " << oldR << endl;
}

int main() {
    int int1 = 0;
    int int2 = 0;
    readInput(int1, int2);
    EEA(int1, int2);

    return 0;
}
