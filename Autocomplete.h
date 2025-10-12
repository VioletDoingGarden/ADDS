#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>
#include "Trie.h"

class Autocomplete {
    private:
        Trie trie;
    public:
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);

};

#endif // AUTOCOMPLETE_H
