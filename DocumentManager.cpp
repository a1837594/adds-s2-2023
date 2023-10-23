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
    if (patrons.find(patronID) != patrons.end() && documents.find(docid) != documents.end()) {
        Document& doc = documents[docid];
        if (doc.patronsWithAccess.size() < doc.licenseLimit) {
            doc.patronsWithAccess.insert(patronID);
            doc.borrowedCopies++;
            return true;
        }
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if (patrons.find(patronID) != patrons.end() && documents.find(docid) != documents.end()) {
        Document& doc = documents[docid];
        if (doc.patronsWithAccess.find(patronID) != doc.patronsWithAccess.end()) {
            doc.patronsWithAccess.erase(patronID);
            doc.borrowedCopies--;
        }
    }
}
