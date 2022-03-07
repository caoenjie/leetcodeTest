//https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/

/*
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。


示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"
 

提示：

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s 和 dictionary[i] 仅由小写英文字母组成
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        std::string res;

        int sl = s.size();
        for(auto dic : dictionary) {
            int dic_len = 0;
            int tmp_len = 0;
            while(tmp_len < sl && dic_len < dic.size()) {
                if(s[tmp_len++] == dic[dic_len]) {
                    dic_len++;
                }
            }

            if(dic_len == dic.size()) {
                if(res.size() < dic.size()) {
                    res = dic;
                } else if(res.size() == dic.size() && res > dic) {
                    res = dic;
                }
            }
        }
        return res;
    }
};

int main() {

    Solution sl;
    std::string s = "abpcplea";
    std::vector<std::string> dictionary = {"ale","apple","monkey","plea"};
    std::cout << sl.findLongestWord(s, dictionary) << "\n";

    return 0;
}