#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

    void reversePrintHelper(Node* node) {
        if (!node) {
            cout << "nullptr";
            return;
        }
        reversePrintHelper(node->next);
        cout << " <- " << node->data;
    }

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        cout << "Head -> ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void reversePrint() {
        cout << "Reverse print the list:" << endl;
        reversePrintHelper(head);
        cout << " <- Head" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.insertAtEnd(25);
    list.insertAtEnd(30);
    list.insertAtEnd(35);
    list.insertAtEnd(40);
    list.insertAtEnd(45);
    list.insertAtEnd(50);

    cout << "Print the list:" << endl;
    list.display();

    list.reversePrint();

    return 0;
}