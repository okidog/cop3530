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

// Same code from 4.1 with minor tweaks
char pop() {
    if (top == 0) {
        cout << "Stack empty, operation skipped" << endl;
    } else {
        cout << stack[--top] << ' ';
        return stack[top]; // Return character for use in display funct
    }
}

void push(char data) { // Now accepts input, removed user input
    if (top == MAX) {
        cout << "Stack is full!" << endl;
        return;
    } else {
        stack[top] = data;
        ++top;
        cout << "Data pushed successfully." << endl;
        return;
    }
}

Node* getNode() { // 3.2 function, but instead of using user input, uses chars from alphabet[] in creation order
    Node* newNode; // This results in a tree with the same order as example I.2 from lec 14
    newNode= (Node*)malloc(sizeof(Node));
    newNode->value = alphabet[alphaPos];
    alphaPos++;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    return newNode;
}

/* Unused for now
void createList(int depth) {
    Node* newNode;
    Node* temp;
    for (int i = 0; i < depth; i++) {
        newNode = getNode();
        if(start == nullptr) {
            start = newNode;
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
*/

void printList(Node* start) { // Same funct as 3.1
    Node* currentNode = start;
    while (currentNode != nullptr) { // Loop until leftChild is nullptr, signifying end of tree depth-wise
        push(currentNode->value);
        currentNode = currentNode->leftChild;
    }
    pop();
    pop();
    currentNode = start->leftChild->rightChild;
    push(currentNode->value);
    pop();
    cout << endl;
}


int main() {
    Node* root = getNode();
    root->leftChild = getNode();
    root->rightChild = getNode();
    root->leftChild->leftChild = getNode();
    root->leftChild->rightChild = getNode();
    root->rightChild->leftChild = getNode();
    root->rightChild->rightChild = getNode();

    return 0;
}