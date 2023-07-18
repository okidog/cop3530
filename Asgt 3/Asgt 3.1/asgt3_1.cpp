#include <iostream>
using namespace std;

/* -------------------------------------------------------------------------------------------------------------------
 * This code works perfectly on Mac and Linux, but segfaults everytime on Windows. I traced it to the loop on line 45
 * not evaluating to true correctly, which for some reason only happens on my Windows development environment. I have
 * included videos of the code running correctly on my Mac.
 * ----------------------------------------------------------------------------------------------------------------*/

class Node {
public:
    char value;
    Node* next;
};

Node* start = nullptr; // Initialization of linked list. Global scope so passing
                        // by reference is not necessary

Node* getNode() {
    Node* newNode;
    newNode= (Node*)malloc(sizeof(Node));
    cout << "Enter data (type char):" << endl;
    cin >> &newNode->value;
    return newNode;
}

void printList(Node* start) {
    Node* currentNode = start;
    while (currentNode != nullptr) { // Loop until next pointer is nullptr, signifying end
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
    static int nodeCount = 1; // Init at 1 for use in insertMid() as an upper bound
    while (temp->next != nullptr) {
        nodeCount++;
        temp = temp->next;
    }
    return nodeCount;
}

void deleteMid(int pos) {
    if (start->next == nullptr) {
        cout << "The list is empty!" << endl; // Can't delete if the list is empty
    } else {
        Node* temp = start;
        Node* prev = start;
        int ctr = 1;
        while (ctr < pos) {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = temp->next;
        free(temp);
    }
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
    cin >> pos;
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
        cout << "Position " << pos << " is not a middle position" << endl;
    }
}

int main() {
    int n = 0;
    int pos = 0;
    cout << "Enter length of linked list: " << endl;
    cin >> n;
    createList(n);
    printList(start);
    cout << "Now deleting from the middle of the list. Select an index: " << endl;
    cin >> pos;
    deleteMid(pos);
    printList(start);
    cout << "Now inserting data into list. " << endl;
    insertMid();
    printList(start);


    return 0;
}