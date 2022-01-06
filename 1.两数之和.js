/*
 * @lc app=leetcode.cn id=1 lang=javascript
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  // 双循环
  // const len = nums.length;
  // for(let i = 0; i < len; i++) {
  //   for(let j = 1; j < len; j++) {
  //     if(nums[i]+nums[j] == target) {
  //       return [i,j];
  //     }
  //   }
  // }
  // return [];

  // map解法
  const map = new Map();
  const len = nums.length;
  for(let i = 0; i < len; i++) {
      if(map.get(nums[i]) != undefined){
          return [map.get(nums[i]),i];
      } 
      map.set(target-nums[i],i);
  }
};
// @lc code=end

