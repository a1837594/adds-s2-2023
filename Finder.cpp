#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    for(size_t i = 1; i <= s2.size(); i++) {
        // size_t found = s1.find(s2.substr(0, i));
        // if (found != string::npos) {
        //     result.push_back(found);
        // } else {
        //     result.push_back(-1);
        //     break;
        // }
        if (const auto it = std::search(s1.begin(), s1.end(),
            std::boyer_moore_searcher(s2.begin(), s2.end()));
        it != s1.end()
        ){
            result.push_back(it - s1.begin());
        }
        else{
            result.push_back(-1);
            break;
        }
    }
    if(result.size()<s2.size()){
        for(int i=0;i<s2.size()-result.size();i++){
            result.push_back(-1);
        }
    }
    return result;
}
