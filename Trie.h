#ifndef TRIE_H
#define TRIE_H


#include <string>
#include <vector>
#include "Node.h"

class Trie{
    private:
        Node* root;
        Node* FindWord(std::string PreWord,std::string& Word, std::vector<std::string>&  ParWord);
        void FindAllWords(Node* node, std::string& PreWord, std::vector<std::string>& res);
        public:
        Trie() :root(new Node()){};
        void Insert(std::string Word);
        void Search(std::string PreWord, std::vector<std::string>& res);
        std::string LongestPrefix(std::string PreWord);

};


#endif // TRIE_H