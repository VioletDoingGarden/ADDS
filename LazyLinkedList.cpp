#include "LazyLinkedList.h"
#include "LazyNode.h"
#include <iostream>

LazyLinkedList::LazyLinkedList() : head(nullptr), deleted_count(0), active_count(0) {}

LazyLinkedList::~LazyLinkedList() {
    LazyNode* current = head;
    while (current != nullptr) {
        LazyNode* next = current->getLink();
        delete current;
        current = next;
    }
}

void LazyLinkedList::insertFront(int val) {
    LazyNode* node = new LazyNode(val);
    node->setLink(head);
    head = node;
    active_count++;
}

void LazyLinkedList::lazyDelete(int val) {
    LazyNode* current = head;
    while (current != nullptr) {
        if (current->getData() == val && !current->isDeleted()) {
            current->markDeleted();
            deleted_count++;
            active_count--;
            break;
        }
        current = current->getLink();
    }
    if (deleted_count >= active_count) {
        cleanup();
    }
}

void LazyLinkedList::cleanup() {
    LazyNode* current = head;
    LazyNode* prev = nullptr;
    while (current != nullptr) {
        if (current->isDeleted()) {
            LazyNode* temp = current;
            if (prev == nullptr) {
                head = current->getLink();
                current = head;
            } else {
                prev->setLink(current->getLink());
                current = prev->getLink();
            }
            delete temp;
            deleted_count--;
        } else {
            prev = current;
            current = current->getLink();
        }
    }
}

void LazyLinkedList::printList() {
    LazyNode* current = head;
    std::cout << "[";
    bool first = true;
    while (current != nullptr) {
        if (!current->isDeleted()) {
            if (!first) std::cout << " ";
            std::cout << current->getData();
            first = false;
        }
        current = current->getLink();
    }
    std::cout << "]\n";
}