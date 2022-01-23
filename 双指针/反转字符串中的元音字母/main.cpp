// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/

/*
给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。

 

示例 1：

输入：s = "hello"
输出："holle"
示例 2：

输入：s = "leetcode"
输出："leotcede"
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string tmp = "aeiouAEIOU";
        int first = 0, end = s.size()-1;
        while(first < end) {
            if(tmp.find(s[first]) == std::string::npos) first++;
            if(tmp.find(s[end]) == std::string::npos) end--;
            if(tmp.find(s[first]) != std::string::npos
                && tmp.find(s[end]) != std::string::npos) swap(s[first++], s[end--]);
        }
        return s;
    }
};

int main(){

    Solution sl;
    std::cout << sl.reverseVowels("leetcode") << "\n";
    return 0;
}
