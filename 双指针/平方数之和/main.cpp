// https://leetcode-cn.com/problems/sum-of-square-numbers/

/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

示例 1：

输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
示例 2：

输入：c = 3
输出：false
示例 3：

输入：c = 4
输出：true
示例 4：

输入：c = 2
输出：true
示例 5：

输入：c = 1
输出：true
*/

#include <iostream>
#include <cmath>


class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = sqrt(c);
        while(i <= j) {
            long long sum = i*i + j*j;
            if(c < sum) j--;
            else if(c > sum) i++;
            else return true;
        }
        return false;
    }
};


int main() {


    return 0;
}