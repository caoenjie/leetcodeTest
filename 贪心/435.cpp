#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 先排序，然后贪心地选择不重叠的区间。
 *
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int cnt = 0;
        int perv = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < perv) {
                cnt++;
            } else {
                perv = intervals[i][1];
            }
        }
        return cnt;

    }
};

