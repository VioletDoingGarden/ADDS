#include "DocumentManager.h"
#include <iostream>

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    docs[id] = {name, license_limit, 0};
    docs_names[name] = id;
}
void DocumentManager::addPatron(int patronID) {
    pats.emplace(patronID, std::unordered_set<int>{});
}   
int DocumentManager::search(std::string name) {
    auto it = docs_names.find(name);
    if (it != docs_names.end()) return it->second;
    return 0; 
}
bool DocumentManager::borrowDocument(int docid, int patronID) {
    auto pats_i = pats.find(patronID);
    if (pats_i == pats.end()) return false;
    auto docs_i = docs.find(docid); 
    if (docs_i == docs.end()) return false;
    if (docs_i->second.curr >= docs_i->second.license_limit) return false; 
    if (pats_i->second.count(docid)) return false; 
    docs_i->second.curr++;
    pats_i->second.insert(docid); 
    return true;
}
void DocumentManager::returnDocument(int docid, int patronID) {
    auto pats_i = pats.find(patronID);
    if (pats_i == pats.end()) return;
    if (pats_i->second.erase(docid) == 0)return;
    auto docs_i = docs.find(docid);
    if (docs_i != docs.end() && docs_i->second.curr > 0) docs_i->second.curr--;
}