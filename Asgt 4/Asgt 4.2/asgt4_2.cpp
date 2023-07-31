#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    char value;
    Node* next;
};

Node* start = nullptr; // Same initialization of start node used in 3.1

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

Node* getNode() {
    Node* newNode;
    newNode= (Node*)malloc(sizeof(Node));
    cout << "Enter data (type char):" << endl;
    cin >> &newNode->value;
    newNode->prev = nullptr; // Same funct as 3.1, two lines added to init prev/next values to nullptr
    newNode->next = nullptr;
    return newNode;
}

void createList(int n) {
    Node* newNode;
    Node* temp;
    for (int i = 0; i < n; i++) {
        newNode = getNode();
        if(start == nullptr) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp; // Only change to modify prev node
        }
    }
}

void printList(Node* start) { // Same funct as 3.1
    Node* currentNode = start;
    while (currentNode != nullptr) { // Loop until next pointer is nullptr, signifying end
        cout << currentNode->value;
        currentNode = currentNode->next;
    }
    cout << endl;
}


int main() {

    return 0;
}