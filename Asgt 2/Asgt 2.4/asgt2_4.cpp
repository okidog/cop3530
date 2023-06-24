#include <iostream>
using namespace std;

class Variables {

    int a = 0;
    int k = 0;
    int n = 0;
    int K[99] = {0};

public:
    void readVariables() {
        cout << "Enter a value for a:" << endl;
        cin >> a;
        cout << "Enter a value for k:" << endl;
        cin >> k;
        cout << "Enter a value for n:" << endl;
        cin >> n;
    }

    void binaryK() {
        int temp = k;
        int i = 0;
        while (temp > 0) {
            K[i] = temp % 2;
            temp = (temp - K[i]) / 2;
            i++;
        }
    }

    int modularExpo() {
        if (n == 1) {
            return 0;
        }
        int b = 1;
        int A = a;
        if (K[0] == 1) {
            b = a;
        }
        for (int i = 1; i < sizeof(K) / sizeof(int); i++) {
            A = A * A % n;
            if (K[i] == 1) {
                b = A * b % n;
            }
        }
        return b;
    }
};

    int main() {
        Variables vars;
        cout << "This program calculates a^k mod n. " << endl;
        vars.readVariables();
        vars.binaryK();
        cout << "Result: " << vars.modularExpo() << endl;
        return 0;
    };
