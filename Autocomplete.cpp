#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

Autocomplete::~Autocomplete() {
    clearTrie();
}

void Autocomplete::clearTrie() {
    deleteTrie(root);
    root = new TrieNode();
}

void Autocomplete::deleteTrie(TrieNode* node) {
    if (!node) return;
    for (TrieNode* child : node->children) {
        if (child) deleteTrie(child);
    }
    delete node;
}

void Autocomplete::insert(std::string word) {
    insertWord(root, word);
}

void Autocomplete::insertWord(TrieNode* node, std::string word) {
    for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* node = root;
    
    for (char c : partialWord) {
        int index = c - 'a';
        if (!node->children[index]) {
            return suggestions; // No suggestions found
        }
        node = node->children[index];
    }
    
    findSuggestions(node, partialWord, suggestions);
    return suggestions;
}

void Autocomplete::findSuggestions(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            char c = 'a' + i;
            findSuggestions(node->children[i], prefix + c, suggestions);
        }
    }
}
