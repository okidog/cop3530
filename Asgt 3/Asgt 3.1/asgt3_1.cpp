#include <iostream>
using namespace std;

class Node {
public:
    char value;
    Node* next;
};

Node* start = nullptr;

Node* getNode() {
    Node* newnode;
    newnode= (Node*)malloc(sizeof(Node));
    cout << "Enter data (type int):" << endl;
    cin >> &newnode->value;
    return newnode;
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
        }
    }
}

void insertBeg() {
    Node* newNode;
    newNode = getNode();
    if (start == nullptr) {
        start = newNode;
    } else {
        newNode->next = start;
        start = newNode;
    }
}

int main() {
    Node* start = nullptr;

    return 0;
}