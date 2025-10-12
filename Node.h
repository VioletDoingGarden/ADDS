#ifndef NODE_H
#define NODE_H

#include <string>
#include <unordered_map>

class Node {
public:
char value;
std::unordered_map<std::string, Node*> children;
bool isWord;
Node() : isWord(false) {};
};

#endif // NODE_H