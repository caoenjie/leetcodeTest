#include <vector>
using namespace std;

/**
 * 左闭又闭写法
 * 找最左边的时，当nums[mid] == target时，r = mid - 1
 * 找最右边的时，当nums[mid] == target时，l = mid + 1
 *
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int first = -1, last = -1;

        // Find the first occurrence
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                first = mid;
                r = mid - 1; // Continue searching in the left half
            }
        }

        l = 0, r = nums.size() - 1;

        // Find the last occurrence
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                last = mid;
                l = mid + 1; // Continue searching in the right half
            }
        }

        return {first, last};

    }
};