/*
 * @lc app=leetcode.cn id=167 lang=java
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0, high = numbers.length-1;
        int sum = 0;
        while(low < high) {
            sum = numbers[low] + numbers[high];
            if (sum == target) {
                return new int[]{low+1,high+1};
            }else if (sum > target) {
                high --;
            }else {
                low ++;
            }
        }
        return new int[]{-1,-1};
    }
}
// @lc code=end

