/*

https://leetcode.com/problems/two-sum/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Keys are the array values and values are the associated array indices
        unordered_map<int, int> hash; // Use as a hash table, instead of creating one
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            if (hash.count(target - nums[i])) // If the partner of this value to reach the target sum has been saved already
            {
                result.push_back(hash[target - nums[i]]); // Get index of other value
                result.push_back(i);
                return result;
            }
            else // Pair has not yet been found, so save value to hash table
                hash[nums[i]] = i;
        return result;
    }
};

int main()
{
    Solution s;
    int arr[] = {2, 7, 11, 15};
    vector<int> nums(arr, arr+4);
    vector<int> test =  s.twoSum(nums , 9);
    cout << test[0] << " " << test[1] <<"\n";
    return 0;
}