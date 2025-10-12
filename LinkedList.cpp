
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
    head = nullptr;
};

LinkedList::LinkedList(int* array, int len) {
    head = new Node(array[0]);
    Node* current = head;
    for (int i = 1; i < len; i++) {
        Node* newNode = new Node(array[i]);
        current->setLink(newNode);
        current = newNode;
    }
};

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->getLink();
        delete current;
        current = next;
    }
};

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (pos <= 1 || head == nullptr) {
        newNode->setLink(head);
        head = newNode;
        return;
    }
    Node* current = head;
    for (int i = 1; i <  pos -1   && current->getLink() != nullptr; i++) {
        current = current->getLink();
    }
    if(current == nullptr) {
        delete newNode;
        return;
    }
    newNode->setLink(current->getLink());
    current->setLink(newNode);
}
bool LinkedList::deletePosition(int pos) {
    if (pos < 1 || head == nullptr) return false;
    if (pos == 1) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }
    Node* current = head;
    for (int i = 1; i < pos - 1 && current != nullptr; i++) {
        current = current->getLink();
    }
    if (current != nullptr && current->getLink() != nullptr) {
        Node* temp = current->getLink();
        current->setLink( temp->getLink() );
        delete temp;
        return true;
    }
    return false;
};

int LinkedList::get(int pos) {
    if (pos < 1 || head == nullptr) return std::numeric_limits<int>::max();
    Node* current = head;
    for (int i = 1; i < pos  && current != nullptr; i++) {
        current = current->getLink();
    }
    if (current != nullptr) {
        return current->getData();
    }
    return -1; 
};

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;
    while (current != nullptr) {
        if (current->getData() == target) {
            return index;
        }
        current = current->getLink();
        index++;
    }
    return -1; 
};

void LinkedList::printList() {
    if (head == nullptr) return;
    
    std::cout << "[";
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getData();
        if (current->getLink() != nullptr) std::cout << " ";
        current = current->getLink();
    }
    std::cout << "]";
};

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->getLink();
        current->setLink(prev);
        prev = current;
        current = next;
    }
    head = prev;
}