import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=763 lang=java
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] codeArr = new int[26];
        int strLen = s.length();

        for (int i = 0; i < strLen; i++) {
            codeArr[s.codePointAt(i) - 'a'] = i;
        }

        List<Integer> list = new ArrayList<Integer>();
        int end =0, start = 0;
        for(int i = 0; i < strLen; i++) {
            end = Math.max(end, codeArr[s.codePointAt(i) - 'a']);
            if (i == end) {
                list.add(end - start +1);
                start = end +1;
            }
        }
        
        return list;
    }
}
// @lc code=end

