#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

/**
 * 需要注意的是need数组的操作
 * --need[s[r]]
 * 每遇到一个目标字符，need[c]--，表示“我们还需要它的数量 -1”
 * 如果这个字符还在我们“需要”的范围内（即 need[c] 原来是 > 0 的），那么我们就算是“匹配到了一个需要的字符”，所以 count++
 * ++need[s[l]] > 0
 * 当窗口中把字符 s[l] 移出时，要将该字符“还回去”
 * 如果这个字符是目标字符，并且移除它会导致 need[c] > 0，说明我们窗口内缺少它了 → count--
 */

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int l = 0, min_l = 0, min_len = INT_MAX;
        int count = 0;
        std::vector<int> need(128, 0);
        std::vector<bool> have(128, 0);
        for(int i = 0; i < t.size(); ++i) {
            need[t[i]]++;
            have[t[i]] = true;
        }
        for(int r = 0; r < s.size(); r++) {
            if(have[s[r]]) {
                if(--need[s[r]] >= 0) count++;
                while(count == t.size()) {
                    if(r - l + 1 < min_len) {
                        min_l = l;
                        min_len = r - l + 1;
                    }
                    if(have[s[l]] && ++need[s[l]] > 0) {
                        count--;
                    }
                    l++;
                }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_l, min_len);
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    solution.minWindow(s, t);
    return 0;
}