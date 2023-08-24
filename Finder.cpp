#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t start = 0;
    for(size_t i = 1; i <= s2.size(); i++) {
        auto found = s1.find(s2.subsstr(0, i), start);
        if (found == string::npos) {
            for(int j  = i; j < s2.size(); j++) {
                result.push_back(-1);
            }
            break;
        }
        else {
            result.push_back(found);
            start = found;
        }
   }
    return result;
}
