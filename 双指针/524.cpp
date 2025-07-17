#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int min_l = 0;
        int min_s = -1;
        for(int i = 0; i < dictionary.size(); i++) {
            int s1 = 0, s2 = 0;
            while(s1 < s.size() && s2 < dictionary[i].size()) {
                if(s[s1++] == dictionary[i][s2]) {
                    s2++;
                }
            }
            if(s2 == dictionary[i].size()) {
                if(min_l < dictionary[i].size()) {
                    min_l = dictionary[i].size();
                    min_s = i;
                } else if( min_l == dictionary[i].size() && dictionary[i] < dictionary[min_s]) {
                    min_s = i;
                }
            }
        }
        return min_s == -1 ? "": dictionary[min_s];
    }
};