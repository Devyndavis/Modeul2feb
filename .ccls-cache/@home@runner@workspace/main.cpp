#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

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

    void deleteFirst() {
        if (!head) return;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteValue(int value) {
        if (!head) return;
        if (head->data == value) {
            deleteFirst();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    ~SinglyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    std::cout << "Build a forward list\n";
    list.insertAtBeginning(50);
    list.insertAtBeginning(40);
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    list.display();

    std::cout << "Delete the first node\n";
    list.deleteFirst();
    list.display();

    std::cout << "Delete the last node\n";
    list.deleteLast();
    list.display();

    std::cout << "Delete the middle node\n";
    list.deleteValue(30);
    list.display();

    SinglyLinkedList reverseList;
    std::cout << "Build a backward list\n";
    reverseList.insertAtEnd(50);
    reverseList.insertAtEnd(40);
    reverseList.insertAtEnd(30);
    reverseList.insertAtEnd(20);
    reverseList.insertAtEnd(10);
    reverseList.display();

    std::cout << "Delete the first node\n";
    reverseList.deleteFirst();
    reverseList.display();

    std::cout << "Delete the last node\n";
    reverseList.deleteLast();
    reverseList.display();

    std::cout << "Delete the middle node\n";
    reverseList.deleteValue(30);
    reverseList.display();

    return 0;
}