#include <iostream>
using namespace std;

class Node {
public:
    Node* leftChild;
    char value;
    Node* rightChild;
};

Node* start = nullptr; // Same initialization of start node used in 3.1

// Used for creating of list. Letters are easier to read than numbers
const char alphabet[26] {'A', 'B','C','D','E','F','G',};
static int alphaPos = 0;

// Init stack
const int MAX = 10; // Max will not change in code, but can be changed for different implementations
int stack[MAX];
int top = 0;

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
        cout << stack[--top];
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
    newNode->value = alphabet[alphaPos];
    newNode->leftChild = nullptr; // Same funct as 3.1, two lines added to init leftChild/rightChild values to nullptr
    newNode->rightChild = nullptr;
    return newNode;
}

void createList(int depth) {
    Node* newNode;
    Node* temp;
    for (int i = 0; i < depth; i++) {
        newNode = getNode();
        if(start == nullptr) {
            start = newNode;
            alphaPos++;
        } else {
            temp = start;
            while (temp->rightChild != nullptr) {
                temp = temp->rightChild;
            }
            temp->rightChild = newNode;
            newNode->leftChild = temp; // Only change to modify leftChild node
        }
    }
}

void printList(Node* start) { // Same funct as 3.1
    Node* currentNode = start;
    while (currentNode != nullptr) { // Loop until rightChild pointer is nullptr, signifying end
        cout << currentNode->value;
        currentNode = currentNode->rightChild;
    }
    cout << endl;
}


int main() {

    return 0;
}