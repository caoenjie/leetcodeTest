/*
 * @lc app=leetcode.cn id=88 lang=java
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m -1, j= n -1;
        int tail = m+n-1;
        while(j>=0){
            if(i==-1 || nums1[i] < nums2[j]){
                nums1[tail] = nums2[j];
                j--;
            } else {
                nums1[tail] = nums1[i];
                i--;
            }
            tail--;
        }
    }
}
// @lc code=end

