/*
 * @lc app=leetcode.cn id=167 lang=javascript
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    // for(let i = 0; i < numbers.length; i++) {
    //     for(let j = i+1; j < numbers.length; j++ ) {
    //         if(target - numbers[i] == numbers[j] ) {
    //             return [i+1,j+1];
    //         }
    //     }
    // }

    let low = 0, high = numbers.length -1;
    let sum = 0;
    while(low < high) {
        sum = numbers[low] + numbers[high];
        if(sum == target) {
            return [low+1, high+1];
        } else if (sum > target) {
            high--;
        } else {
            low++;
        }
    }
};
// @lc code=end

