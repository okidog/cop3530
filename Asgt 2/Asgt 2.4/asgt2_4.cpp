#include <iostream>
using namespace std;

void readVariables(int& a, int& k, int& n) {
    cout << "Enter a value for a:" << endl;
    cin >> a;
    cout << "Enter a value for k:" << endl;
    cin >> k;
    cout << "Enter a value for n:" << endl;
    cin >> n;
}

void binaryK(int& k, int K[]) {
    int temp = k;
    for (int i = 0; temp > 0; i++) {
        K[i] = temp % 2;
        temp = (temp-K[i]/2);
    }
}

int modularExpo(int& a, int K[], int& n) {
    if (n == 1) {
        return 0;
    }
    int b = 1;
    if (K == 0) {
        return b;
    }
    int A = a;
    if (K[0] == 1) {
        b = a;
    }
    for (int i = 0; i < 9; i++) {
        A = A * A % n;
        if (K[i] == 1) {
            b = A*b % n;
        }
    }
    return b;
}

int main() {
    int a = 0;
    int k = 0;
    int n = 0;
    int K[99] = {0};
    cout << "This program calculates a^k mod n." << endl;
    readVariables(a, k, n);
    binaryK(k, K);
    cout << "Result: " << modularExpo(a, K, n) << endl;
    return 0;
};