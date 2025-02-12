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
    Node* tail;
    int count;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void display(const string& listName) {
        Node* current = head;
        cout << listName << " (" << count << "): ";
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void clear() {
        head = tail = nullptr;
        count = 0;
    }

    Node* getHead() { return head; }
};

class SplitLinkedList : public SinglyLinkedList {
public:
    void splitEvenOdd(SinglyLinkedList& evens, SinglyLinkedList& odds) {
        Node* current = getHead();
        while (current) {
            if (current->data % 2 == 0) {
                evens.append(current->data);
            } else {
                odds.append(current->data);
            }
            current = current->next;
        }
    }
};

int main() {
    SplitLinkedList sll;
    int num;
    cout << "Enter integers ending with -999:" << endl;
    while (cin >> num && num != -999) {
        sll.append(num);
    }

    sll.display("list");

    SinglyLinkedList evenList, oddList;
    sll.splitEvenOdd(evenList, oddList);

    evenList.display("evensList");
    oddList.display("oddsList");

    sll.clear();
    sll.display("list");

    return 0;
}
