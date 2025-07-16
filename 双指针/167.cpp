#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            int sum  = numbers[left] + numbers[right];
            if(sum == target) {
                return {left + 1, right + 1}; // 返回1-based索引
            } else if(sum < target) {
                left++; // 增加左指针
            } else {
                right--; // 减少右指针
            }
        }
        return {};
    }
};