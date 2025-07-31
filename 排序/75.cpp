#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> colorCount;
        for (int num : nums) {
            colorCount[num]++;
        }

        int index = 0;
        for (int color = 0; color <= 2; ++color) {
            while (colorCount[color] > 0) {
                nums[index++] = color;
                colorCount[color]--;
            }
        }
    }
};