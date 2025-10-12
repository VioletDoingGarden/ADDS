#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H


#include "Trie.h"
#include <unordered_map>

class PrefixMatcher {
private:
    Trie trie;
    std::unordered_map<std::string, int> map;
public:
void insert(std::string address, int routerNumber); // add a router address
int selectRouter(std::string networkAddress);
};


#endif // PREFIXMATCHER_H