/*
 * @lc app=leetcode.cn id=88 lang=javascript
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  let i = m-1, j = n-1;
  let tail = m+n-1;
  while(j >= 0) {
      if(i == -1) {
          nums1[tail] = nums2[j]
          j--
      }else if (nums1[i] <= nums2[j]) {
          nums1[tail] = nums2[j]
          j--;
      }else {
          nums1[tail] = nums1[i]
          i--;
      }
      tail--;
  }
  return nums1;
};
// @lc code=end

