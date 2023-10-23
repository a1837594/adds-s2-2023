#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <unordered_map>
#include <set>

class DocumentManager {
private:
    struct Document {
        int docID;
        int licenseLimit;
        int borrowedCopies;
        std::set<int> patronsWithAccess;
    };

    std::unordered_map<std::string, Document> documents;
    std::unordered_map<int, bool> patrons;

    int nextDocID;
public:
    DocumentManager();

    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);

};

#endif