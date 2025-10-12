#include "Autocomplete.h"

void Autocomplete::insert(std::string word) {
    this->trie.Insert(word);
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> res;
    this->trie.Search(partialWord, res);
    return res;
}