#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 简单的贪心，只要饼干尺寸大于等于孩子的需求，就满足了孩子的需求。
 * 先对孩子的需求和饼干的尺寸进行排序，然后用两个指针遍历。
 * 一个指针遍历孩子的需求，另一个指针遍历饼干的尺寸。
 * 如果当前饼干的尺寸满足当前孩子的需求，就满足了这个孩子的需求，指针都向前移动。
 * 如果当前饼干的尺寸不满足当前孩子的需求，指针只移动饼干的指针，
 * 继续寻找下一个饼干。
 * 最终返回满足的孩子数量。
 * 时间复杂度是O(nlogn)，其中n是孩子或饼干的数量。
 * 空间复杂度是O(1)，只使用了常数级的额

*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while(child < g.size() && cookie < s.size()) {
            if(s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }
        return child;

    }
};