#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 贪心策略，今天价格比昨天高，就计入累计收益
 *
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i = 1; i < prices.size(); i++) {
            sum += std::max(prices[i] - prices[i -1], 0);
        }
        return sum;
    }
};