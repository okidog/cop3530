#include <iostream>
using namespace std;

class Node {
public:
    char value;
    Node* next;
};

Node* start = nullptr;

Node* getNode() {
    Node* newNode;
    newNode= (Node*)malloc(sizeof(Node));
    cout << "Enter data (type char):" << endl;
    cin >> &newNode->value;
    return newNode;
}

void printList(Node* start) {
    Node* currentNode = start;
    while (currentNode != nullptr) {
        cout << currentNode->value;
        currentNode = currentNode->next;
    }
    cout << endl;
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

int countNode(Node* start) {
    Node* temp = start;
    static int nodeCount = 1;
    while (temp->next != nullptr) {
        nodeCount++;
        temp = temp->next;
    }
    return nodeCount;
}

void insertMid() {
    Node* newNode;
    Node* temp;
    Node* prev;
    int pos = 0;
    int nodectr = 0;
    int ctr = 1;
    newNode = getNode();
    cout << "Enter position: " << endl;
    scanf("%d", &pos);
    nodectr = countNode(start);
    if (pos > 1 && pos < nodectr) {
        temp = prev = start;
        while (ctr < pos) {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newNode;
        newNode->next = temp;
    } else {
        cout << "Position %d is not a middle position" << endl;
    }
}

int main() {
    int n = 0;
    cout << "Enter length of linked list: " << endl;
    cin >> n;
    createList(n);
    printList(start);
    cout << "Now inserting data into list. " << endl;
    insertMid();
    printList(start);


    return 0;
}