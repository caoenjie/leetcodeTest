// https://leetcode-cn.com/problems/partition-labels/

/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
返回一个表示每个字符串片段的长度的列表。


示例：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_char(26);
        for(int i = 0; i < s.size(); i++) {
            last_char[s[i] - 'a'] = i;
        }

        vector<int> part_list;
        int first = last = 0;
        while(first < s.size()) {
            last = first;
            for(int i = first; i < s.size() && i <= last; i++) {
                int index = last_char[s[i] - 'a'];
                if(index > last) last = index;
            }
            part_list.push_back(last - first + 1);
            first = last + 1;
        }

        return part_list;
    }
};

int main() {


    return 0;
}