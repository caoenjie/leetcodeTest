/*
 * @lc app=leetcode.cn id=605 lang=javascript
 *
 * [605] 种花问题
 */

// @lc code=start
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
  const len = flowerbed.length;
    for(let i = 0; i < len && n > 0;) {
        if(flowerbed[i] == 1) {
            i+=2;
        }else if (i == len-1 || flowerbed[i+1] == 0) {
            n--;
            i+=2;
        }else {
            i+=3;
        }
    }

    return n == 0;
};
// @lc code=end

