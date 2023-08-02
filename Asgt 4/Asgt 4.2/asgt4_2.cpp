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
Node* stack[MAX];
int top = 0;

// Same code from 4.1 with minor tweaks
Node* pop() {
    if (top == 0) {
        cout << "Stack empty, operation skipped" << endl;
    } else {
        cout << stack[--top]->value << ' ';
        return stack[top]; // Return character for use in display funct
    }
}

void push(Node* data) { // Now accepts input, removed user input
    if (top == MAX) {
        cout << "Stack is full!" << endl;
        return;
    } else {
        stack[top] = data;
        ++top;
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

void printList(Node* start) { // Loosely based on printList from 3.2
    Node* currentNode = start;
    if (currentNode == nullptr) {
        cout << "The tree is empty!" << endl;
    } else {
        while (currentNode->leftChild != nullptr){ //
            push(currentNode);
            currentNode = currentNode->leftChild;
        };
        push(currentNode);
        pop();
        currentNode = pop(); // Pop twice and prepare for evaluation of right child
        currentNode = currentNode->rightChild;
        push(currentNode);
        pop();
        currentNode = pop(); // Back to root, now traverse right side
        currentNode = currentNode->rightChild;
        push(currentNode);
        currentNode = currentNode->leftChild;
        push(currentNode);
        pop();
        currentNode = pop();
        currentNode = currentNode->rightChild;
        push(currentNode);
        pop();


    }
}


int main() {
    Node* root = getNode();
    root->leftChild = getNode();
    root->rightChild = getNode();
    root->leftChild->leftChild = getNode();
    root->leftChild->rightChild = getNode();
    root->rightChild->leftChild = getNode();
    root->rightChild->rightChild = getNode();

    printList(root);

    return 0;
}