#include "PrefixMatcher.h"

void PrefixMatcher::insert(std::string address, int routerNumber) {
    this->trie.Insert(address);
    this->map[address] = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    std::string res = this->trie.LongestPrefix(networkAddress);
    return this->map[res];
}