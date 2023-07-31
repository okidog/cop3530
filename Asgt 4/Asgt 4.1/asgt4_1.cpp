#include <iostream>
using namespace std;

// Init stack
const int MAX = 10; // Max will not change in code, but can be changed for different implementations
int stack[MAX];
int top = 0;

int menu() {
    int choice;
    cout << "1. Push\n2. Pop\n3. Display\n4. Quit" << endl;
    cin >> choice;
    return choice;
}

void display() {
    if (top == 0) {
        cout << "The stack is empty!" << endl;
    } else {
        for (int i = 0; i < top; i++) {
            cout << "pos " << i+1 << ": "<< stack[i] << endl;
        }
    }
}

void pop() {
    if (top == 0) {
        cout << "Stack empty, operation skipped" << endl;
    } else {
        cout << stack[--top] << endl;
    }
}

void push() {
    int data = 0;
    if (top == MAX) {
        cout << "Stack is full!" << endl;
        return;
    } else {
        cout << "Enter data:" << endl;
        cin >> data;
        stack[top] = data;
        ++top;
        cout << "Data pushed successfully." << endl;
        return;
    }
}

int main() {
    int choice = 0;
    do {
        choice = menu();
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    } while (true);
}