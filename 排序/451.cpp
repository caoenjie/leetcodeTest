#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        string result;
        for (const auto& p : freqVec) {
            result.append(p.second, p.first);
        }

        return result;
    }
};