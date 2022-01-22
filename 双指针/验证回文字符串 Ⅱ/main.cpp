// https://leetcode-cn.com/problems/valid-palindrome-ii/

/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

 

示例 1:

输入: s = "aba"
输出: true
示例 2:

输入: s = "abca"
输出: true
解释: 你可以删除c字符。
示例 3:

输入: s = "abc"
输出: false
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int cnt = 0;
        int first = 0, end = s.size()-1;
        while(first < end) {
            if(s[first] == s[end]) {
                first++;
                end--;
                continue;
            }
            int f1 = first;
            int e1 = end;
            f1--;
            while(f1 < e1) {
                if(s[f1] == s[e1]) {
                    f1++;
                    e1--;
                } else {
                    break;
                }
            }
            if(f1 >= e1) return true;
            end--;
            while(first < end) {
                if(s[first] == s[end]) {
                    first++;
                    end--;
                }else {
                    return false;
                }
            }
            return true;
        }
        std::cout << "cnt: " << cnt;
        return true;

    }
};

int main() {
    Solution sl;
    std::cout << sl.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << std::endl;

    return 0;
}