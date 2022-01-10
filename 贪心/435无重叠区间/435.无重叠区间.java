import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=435 lang=java
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length == 0) 
            return 0;
        
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[1] - interval2[1];
            }
        });
        int n = intervals.length;
        int ans = 1;
        int right = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }

        return n-ans;
        
    }
}
// @lc code=end

