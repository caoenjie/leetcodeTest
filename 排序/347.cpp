#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> result;
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        std::vector<std::pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
        std::sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }
        return result;
    }
};