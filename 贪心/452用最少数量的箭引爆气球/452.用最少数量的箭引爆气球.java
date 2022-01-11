/*
 * @lc app=leetcode.cn id=452 lang=java
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>(){
            public int compare (int[] a, int[] b) {
                return Integer.compare(a[1],b[1]);
            }
        });

        int pos = points[0][1];
        int ans = 1;
        for(int[] balloon : points) {
            if(balloon[0] > pos) {
                pos = balloon[1];
                ans++;
            }
        }
        return ans;
    }
}
// @lc code=end

