#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 贪心拿到每个字符最后一次出现的最远位置，然后切割字符串。
 *
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::vector<int> last(26, -1);
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        std::vector<int> result;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if(i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};