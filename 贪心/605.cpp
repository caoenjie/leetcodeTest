#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 考虑到花坛的边界情况，花坛的第一个和最后一个位置可以单独处理。
 *
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && ( i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        return cnt >= n;
    }
};

int main() {
    Solution solution;
    vector<int> flowerbed = {1,0,0,0,1,0,0};
    int n = 2;
    bool result = solution.canPlaceFlowers(flowerbed, n);
    // print flowerbed
    for (int i = 0; i < flowerbed.size(); i++) {
        cout << flowerbed[i] << " ";
    }
    cout << endl;

    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}