#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 先按照身高由高到低，前面的人又少到多的顺序排序，此时相对位置已经确认, 依次插入即可
 * 必须说明一点，只有这样排序，后面插入的时候，才不会影响之前已经排序的人的相对位置
 *  sort {{ 9, 0 }{ 7, 0 }{ 6, 0 }{ 6, 2 }{ 5, 2 }{ 5, 3 }{ 3, 0 }{ 3, 4 }{ 2, 7 }{ 1, 9 }
 *  i = 0 {{ 9, 0 }
    i = 1 {{ 7, 0 }{ 9, 0 }
    i = 2 {{ 6, 0 }{ 7, 0 }{ 9, 0 }
    i = 3 {{ 6, 0 }{ 7, 0 }{ 6, 2 }{ 9, 0 }
    i = 4 {{ 6, 0 }{ 7, 0 }{ 5, 2 }{ 6, 2 }{ 9, 0 }
    i = 5 {{ 6, 0 }{ 7, 0 }{ 5, 2 }{ 5, 3 }{ 6, 2 }{ 9, 0 }
    i = 6 {{ 3, 0 }{ 6, 0 }{ 7, 0 }{ 5, 2 }{ 5, 3 }{ 6, 2 }{ 9, 0 }
    i = 7 {{ 3, 0 }{ 6, 0 }{ 7, 0 }{ 5, 2 }{ 3, 4 }{ 5, 3 }{ 6, 2 }{ 9, 0 }
    i = 8 {{ 3, 0 }{ 6, 0 }{ 7, 0 }{ 5, 2 }{ 3, 4 }{ 5, 3 }{ 6, 2 }{ 2, 7 }{ 9, 0 }
    i = 9 {{ 3, 0 }{ 6, 0 }{ 7, 0 }{ 5, 2 }{ 3, 4 }{ 5, 3 }{ 6, 2 }{ 2, 7 }{ 9, 0 }{ 1, 9 }
 */

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](const auto& a, const auto& b){
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        std::vector<std::vector<int>> res;
        res.push_back(people[0]);
        for(int i = 1; i < people.size(); i++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};


int main() {
    std::vector<std::vector<int>> people{{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};
    Solution s;
    s.reconstructQueue(people);

}