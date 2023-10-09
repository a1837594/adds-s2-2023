#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

PrefixMatcher::~PrefixMatcher() {
    deleteTrie(root);
}

void PrefixMatcher::deleteTrie(TrieNode* node) {
    if (!node) return;
    deleteTrie(node->children[0]);
    deleteTrie(node->children[1]);
    delete node;
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    insertAddress(root, address, routerNumber);
}

void PrefixMatcher::insertAddress(TrieNode* node, std::string address, int routerNumber) {
    for (char c : address) {
        int index = c - '0';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    return findLongestMatchingPrefix(root, networkAddress);
}

int PrefixMatcher::findLongestMatchingPrefix(TrieNode* node, std::string address) {
    int result = -1;
    
    for (char c : address) {
        int index = c - '0';
        if (!node->children[index]) {
            break;
        }
        node = node->children[index];
        if (node->routerNumber != -1) {
            result = node->routerNumber;
        }
    }
    
    return result;
}
