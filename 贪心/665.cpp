#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 当nums[i] > nums[i + 1]时,假设只有只修改一次就可以成为非递减数组。
 * 当i == 0时，必然是把nums[i]修改成更小的值才能保留更长的合法前缀
 * 当i > 0时，可能是把nums[i]修改成更小的值，也可能是把nums[i + 1]修改成更大的值。
 * 如果修改nums[i]，则需要保证nums[i - 1] <= nums[i + 1]。
 * 否则需要修改nums[i + 1] 修改成更大的值
 * 如果修改次数超过1次，则返回false。
 *
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                cnt++;
                if(cnt > 1) return false;

                //[3 3 2 4 6 7]
                if(i > 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i]; // 修改nums[i + 1]让它变大
                } else {
                    nums[i] = nums[i + 1]; // 修改nums[i]让它变小
                }
            }
        }
        return cnt <= 1;
    }
};