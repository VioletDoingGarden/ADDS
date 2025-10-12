

#include "Trie.h"
#include <unordered_map>

void Trie::Insert(std::string Word){
    Node* cur = root;
    for(char& i : Word){
        std::string val(1, i);
        if(cur->children.find(val) == cur->children.end()){
            cur->children.insert({val, new Node()});
        }
        cur = cur->children.find(val)->second;
    }
    cur->isWord = true;
}

void Trie::Search(std::string PreWord, std::vector<std::string> &res)
{
    std::string Word;
    Node* cur = this->FindWord(PreWord, Word, res);
    if(Word == PreWord){
        this->FindAllWords(cur, Word, res);
    };
}

void Trie::FindAllWords(Node* node, std::string& PreWord, std::vector<std::string>& res){
    if(node->isWord){
        res.push_back(PreWord);
    }
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        std::string oldPreWord = PreWord; 
        PreWord += it->first;
        FindAllWords(it->second, PreWord, res);
        PreWord = oldPreWord; 
    }
}

Node* Trie::FindWord(std::string PreWord,std::string& Word, std::vector<std::string>&  ParWord){
    Node* cur = root;
    for(char i : PreWord){
        std::string val(1, i);
        if(cur->children.find(val) == cur->children.end()){
            break;
        }
        else{
            Word += val;
            cur = cur->children.find(val)->second;
            if(cur->isWord){
                ParWord.push_back(Word);
            }
        }
    }
    return cur;
}

std::string Trie::LongestPrefix(std::string PreWord){
    std::string Word;
    std::vector<std::string> ParWord;
    this->FindWord(PreWord, Word, ParWord);
    return ParWord.back();
}