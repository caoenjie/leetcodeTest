import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=455 lang=java
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int index = 0;
        int glen = g.length, slen = s.length;
        for(int i = 0, j = 0; i < glen && j < slen; i++,j++){
            while(j < slen && g[i] > s[j]) {
                j++;
            }
            if(j < slen) {
                index++;
            }
        }
        return index;
    }
}
// @lc code=end

