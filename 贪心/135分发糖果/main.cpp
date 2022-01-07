//https://leetcode-cn.com/problems/candy/
/**
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

示例 1：

输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
示例 2：

输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */

#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int size = ratings.size();
        std::vector<int> sum(size, 1);
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) {
                sum[i]  = sum[i - 1] + 1; //永远只比较右边的大小
            }
        }

        for(int i = size - 1; i > 0; i--) {
            if(ratings[i - 1] > ratings[i]) {
                //比较左边的大小，需要比较原来的大还是+1的大，不能比原来的数还小
                sum[i - 1] = std::max(sum[i - 1], sum[i] + 1);
            }
        }

        return std::accumulate(sum.begin(), sum.end(), 0);
    }
};

int main() {

    std::vector<int> v = {1,3,4,5,2};

    Solution s;
    std::cout << "sum: " << s.candy(v) << "\n";

    return 0;
}