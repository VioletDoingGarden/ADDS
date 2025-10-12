#ifndef LAZY_LINKEDLIST_H
#define LAZY_LINKEDLIST_H
#include "LazyNode.h"

class LazyLinkedList {
private:
    LazyNode* head;
    int deleted_count;
    int active_count;
    void cleanup();
public:
    LazyLinkedList();
    ~LazyLinkedList();
    void insertFront(int val);
    void lazyDelete(int val);
    void printList();
};

#endif