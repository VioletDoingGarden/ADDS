#ifndef DOCUMENT_MANAGER_HPP
#define DOCUMENT_MANAGER_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
private:
    struct DocumentInfo {
        std::string name;
        int license_limit;
        int curr = 0;
    };
    std::unordered_map<int, DocumentInfo> docs;
    std::unordered_map<std::string, int> docs_names;
    std::unordered_map<int, std::unordered_set<int>> pats;
public:
    DocumentManager() = default;
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
};

#endif // DOCUMENT_MANAGER_HPP  