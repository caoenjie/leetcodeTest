#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate
using namespace std;

/**
 * 初始化一个糖果数组，每个孩子至少有一个糖果。
 * 两次遍历，第一次从左到右遍历，如果右边的孩子比左边的孩子评分高，则右边的孩子糖果数比左边的孩子多1。
 * 第二次从右到左遍历，如果左边的孩子比右边的孩子评分高，则判断左边孩子的糖果数是否比右边孩子加上一个后还多
 * 如果是，遵从贪心原则不再分配糖果，否则将左边孩子的糖果数设置为右边孩子的糖果数加1。
 * 最终返回所有孩子的糖果数之和。
 *
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        std::vector<int> candies(ratings.size(), 1);
        for(int i = 0; i < ratings.size() - 1; i++) {
            if(ratings[i + 1] > ratings[i]) {
                candies[i + 1] = candies[i] + 1;
            }
        }

        for(int i = ratings.size() - 1; i > 0; i--) {
            if(ratings[i  - 1] > ratings[i]) {
                candies[i - 1] = std::max(candies[i - 1], candies[i] + 1);
            }
        }

        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution solution;
    vector<int> ratings = {1,3,4,5,2};
    cout << "Minimum candies needed: " << solution.candy(ratings) << endl;
    return 0;
}