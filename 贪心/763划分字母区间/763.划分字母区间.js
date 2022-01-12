/*
 * @lc app=leetcode.cn id=763 lang=javascript
 *
 * [763] 划分字母区间
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function(s) {
  const len = s.length;
  const codeArr = new Array(26);
  const codePointA = "a".codePointAt(0);

  for(let i = 0; i < len; i++) {
      codeArr[s.codePointAt(i)-codePointA] = i;
  }
  let end = start = 0;
  const partition = [];
  for(let i = 0; i < len; i++) {
      end = Math.max(end, codeArr[s.codePointAt(i)-codePointA]);
      if(i == end) {
          partition.push(end-start+1);
          start = end +1;
      }
  }
  return partition;
};
// @lc code=end

