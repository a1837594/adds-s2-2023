#pragma once
#include <string>

class PrefixMatcher {
public:
    PrefixMatcher();
    ~PrefixMatcher();
    
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber);

private:
    struct TrieNode {
        TrieNode* children[2];
        int routerNumber;
        TrieNode() : routerNumber(-1) {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };
    
    TrieNode* root;
    
    void insertAddress(TrieNode* node, std::string address, int routerNumber);
    int findLongestMatchingPrefix(TrieNode* node, std::string address);
};

#endif // PREFIXMATCHER_H
