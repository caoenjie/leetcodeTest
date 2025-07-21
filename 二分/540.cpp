#include <vector>
using namespace std;

/**
 * 确保mid必须是偶数，当mid是奇数时，将其减一，让mid指向索引的偶数位
 * 如果mid和mid+1相等，说明单独的元素在右边，移动左指针到mid+2
 * 如果mid和mid+1不相等，说明单独的元素在左边
 * 最终当左指针和右指针相遇时，左指针指向的就是那个单独的元素
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};