
/**
 * 第一个需要注意整数溢出
 * 第二个题目要求向下取整，退出循环时r < l,返回r
 *
 */


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1, r = x / 2;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            long long sqr = (long long)mid * mid;
            if(sqr == x) {
                return mid;
            } else if(sqr < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};