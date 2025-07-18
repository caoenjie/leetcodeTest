#include <iostream>
#include <vector>
using namespace std;

/**
 * 二分查找
 * 当nums[mid] == nums[l] 无法判断有序区间时，直接将左指针 l 向右移动一位
 * 当nums[mid] <= nums[r] 时，说明右半部分有序
 *   如果 target 在 mid 和 r 之间，则将左指针 l 移动到 mid + 1
 *   否则将右指针 r 移动到 mid - 1
 * 当nums[mid] > nums[r] 时，说明左半部分有序
 *   如果 target 在 l 和 mid 之间，则将右指针 r 移动到 mid - 1
 *   否则将左指针 l 移动到 mid + 1
 * 时间复杂度 O(log n)
 * 空间复杂度 O(1)
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] == nums[l]) {
                l++;
            } else if(nums[mid] <= nums[r]) {
                if(nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if(nums[mid] > target && nums[l] <= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};