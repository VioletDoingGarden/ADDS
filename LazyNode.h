#ifndef LAZY_NODE_H
#define LAZY_NODE_H

class LazyNode {
private:
    int data;
    LazyNode* link;
    bool deleted;
public:
    LazyNode(int val) : data(val), link(nullptr), deleted(false) {}
    int getData() { return data; }
    LazyNode* getLink() { return link; }
    void setLink(LazyNode* next) { link = next; }
    bool isDeleted() { return deleted; }
    void markDeleted() { deleted = true; }
};

#endif