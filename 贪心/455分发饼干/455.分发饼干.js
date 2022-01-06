/*
 * @lc app=leetcode.cn id=455 lang=javascript
 *
 * [455] 分发饼干
 */

// @lc code=start
/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
  let index = 0;
  g.sort((a,b) => a-b)
  s.sort((a,b) => a-b)

  for(let i=0,j=0; i<g.length && j<s.length; i++,j++) {
      while(j < s.length && g[i] > s[j]) {
          j++;
      }
      if(j < s.length) {
          index ++;
      }
  }
  return index;
};
// @lc code=end

