import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int len = nums.length;
        int[] arr = new int[2];
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();

        // 双循环
        // for(int i = 0; i < len; i++) {
        //     for(int j = i+1; j < len; j++) {
        //         if(nums[i]+nums[j] == target) {
        //             arr[0] = i;
        //             arr[1] = j;
        //             return arr;
        //         }
        //     }
        // }
        // return arr;

        for(int i=0; i<len; i++) {
            if(map.containsKey(nums[i])) {
                arr[0] = map.get(nums[i]);
                arr[1] = i;
                return arr;
            }
        }
        return arr;
    }
}   
// @lc code=end
