#pragma once
#include <string>
#include <vector>

class Autocomplete {
public:
    Autocomplete();
    ~Autocomplete();
    
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);

private:
    struct TrieNode {
        std::vector<TrieNode*> children;
        bool isEndOfWord;
        TrieNode() : children(26, nullptr), isEndOfWord(false) {}
    };
    
    TrieNode* root;
    
    void insertWord(TrieNode* node, std::string word);
    void findSuggestions(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);
};

#endif // AUTOCOMPLETE_H
