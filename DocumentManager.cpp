#include "DocumentManager.h"

DocumentManager::DocumentManager() : nextDocID(1) {}

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    if (documents.find(name) == documents.end()) {
        documents[name] = {nextDocID++, license_limit, 0, {}};
    }
}

void DocumentManager::addPatron(int patronID) {
    patrons[patronID] = true;
}

int DocumentManager::search(std::string name) {
    if (documents.find(name) != documents.end()) {
        return documents[name].docID;
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    bool check=false;
    std::string name;
    for(const auto&pair : documents){
        Document dc=pair.second;
        bool check2=false;
        if(dc.docID==docid){
            check=true;
            check2=true;
            name=pair.first;
        };
        if(check2==true)break;
    }
    if(check=false)return false;
    if (patrons.find(patronID) != patrons.end()) {
        Document& doc = documents[name];
        if (doc.patronsWithAccess.size() < doc.licenseLimit) {
            doc.patronsWithAccess.insert(patronID);
            doc.borrowedCopies++;
            return true;
        }
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    bool check=false;
    std::string name;
    for(const auto&pair : documents){
        Document dc=pair.second;
        bool check2=false;
        if(dc.docID==docid){
            check=true;
            check2=true;
            name=pair.first;
        };
        if(check2==true)break;
    }
    if (patrons.find(patronID) != patrons.end()&&!name.empty()) {
        Document& doc = documents[name];
        if (doc.patronsWithAccess.find(patronID) != doc.patronsWithAccess.end()) {
            doc.patronsWithAccess.erase(patronID);
            doc.borrowedCopies--;
        }
    }
}
