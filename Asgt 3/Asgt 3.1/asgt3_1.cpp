#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int newValue) {
        value = newValue;
        next = nullptr;
    }
};

void printList(Node head) {
    Node currentNode = head;
    while (currentNode.next != nullptr) {
        cout << currentNode.value << endl;
        currentNode = currentNode.next;
    }
}

int main() {
    Node node1 = 1;
    Node node2 = 2;
    Node node3 = 3;
    Node node4 = 4;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;

    printList(node1);
    return 0;
}