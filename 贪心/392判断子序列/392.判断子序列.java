/*
 * @lc app=leetcode.cn id=392 lang=java
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
    public boolean isSubsequence(String s, String t) {
        int slen = s.length(),tlen = t.length();
        int i = 0, j = 0;
        while(i < slen && j < tlen) {
            if(s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }
        return i == slen;
    }
}
// @lc code=end

