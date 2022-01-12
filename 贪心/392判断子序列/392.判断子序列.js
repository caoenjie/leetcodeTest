/*
 * @lc app=leetcode.cn id=392 lang=javascript
 *
 * [392] 判断子序列
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
  if(!s.length) return true;
  let index = 0;
  let slen = s.length;
  for(let i = 0; i < t.length; i++) {
      if (t[i] == s[index]) {
          index++;
          if(index == slen) {
              return true;
          }
      }
  }
  return false;
};
// @lc code=end

