#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    char value;
    Node* next;
};

Node* start = nullptr; // Same initialization of start node used in 3.1

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

void delEnd() {
    if (start->next == nullptr) {
        cout << "The list is empty!" << endl;
    } else {
        Node* temp = start;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        free(temp);
    }
}

void insBeg() {
    Node* newNode = getNode();
    if (start->next == nullptr) {
        start = newNode;
    } else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}

int main() {
    int n = 0;
    cout << "Enter size of list:" << endl;
    cin >> n;
    createList(n);
    printList(start);
    cout << "Now deleting the end node." << endl;
    delEnd();
    printList(start);
    cout << "Now inserting a new node at the beginning of the list." << endl;
    insBeg();
    printList(start);
    return 0;
}