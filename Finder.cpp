#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result;
        
        for(size_t i = 1; i <= s2.size(); i++) {
            int tmp ;
            if(result.empty()){
                tmp = 0;
            } else {
                tmp = result.back() + 1;
            }
            size_t found = s1.find(s2.substr(0, i), tmp);
            if (found != string::npos) {
                result.push_back(found);
            } else {
                result.push_back(-1);
                for(size_t j = i + 1; j <= s2.size(); j++) {
                    result.push_back(-1);
                }
                return result;
            }
        }
        return result;
    }

   