#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int target = nums.size() - k;
        while (l < r) {
            int pivot = nums[l];
            int i = l, j = r;
            while(i < j) {
                while(i < j && nums[j] >= pivot) --j;
                while(i < j &&nums[i] <= pivot) ++i;
                if(i < j) swap(nums[i], nums[j]);
            }
            swap(nums[i], nums[l]);
            if(i == target) {
                return nums[i];
            } else if(i < target) {
                l = i + 1;
            } else {
                r = i - 1;
            }
        }
        return nums[l];
    }
};