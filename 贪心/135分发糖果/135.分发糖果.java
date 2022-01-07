import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=135 lang=java
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
    public int candy(int[] ratings) {
        int[] left = new int[ratings.length];
        Arrays.fill(left, 1);

        for(int i = 1; i < ratings.length; i++) {
            if(ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] +1;
            }
        }

        int right = 0;
        for(int i = ratings.length-1; i >= 0 ; i--) {
            if(i < ratings.length-1 && ratings[i] > ratings[i+1]) {
                left[i] = Math.max(left[i], left[i+1]+1);
            }
            right += left[i];
        }

        return right;
    }
}
// @lc code=end

