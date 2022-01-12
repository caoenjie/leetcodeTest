/*
 * @lc app=leetcode.cn id=665 lang=java
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
    public boolean checkPossibility(int[] nums) {
        int n = nums.length;
        int ant = 0;
        for(int i = 0; i < n - 1; ++i) {
            int x = nums[i], y = nums[i + 1];
            if(x > y) {
                ant++;
                if (ant > 1) {
                    return false;
                }
                if (i > 0 && y < nums[i-1]) {
                    nums[i+1] = x;
                }
            }
        }
        return true;
    }
}
// @lc code=end

