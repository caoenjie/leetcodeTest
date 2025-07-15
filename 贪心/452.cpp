#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 贪心算法：先排序，然后贪心地选择不重叠的区间。
 *
 */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 1;

        std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int prev = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            if(prev < points[i][0]) {
                cnt++;
                prev = points[i][1];
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    int result = solution.findMinArrowShots(points);
    cout << "Minimum number of arrows needed: " << result << endl; // Output: 2
    return 0;
}