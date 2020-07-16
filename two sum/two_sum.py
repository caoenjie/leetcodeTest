'''
https://leetcode.com/problems/two-sum/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

'''

class Solution(object):
    def twoSum(self, nums, target):
        num_to_index = {}
        for i, num in enumerate(nums):
            if target - num in num_to_index:
                return [num_to_index[target - num], i]
            num_to_index[num] = i
        return []

if __name__ == "__main__":
    # s = Solution()
    # index = s.twoSum([2, 7, 11, 15], 9)
    # print(index)
    test = {1:1, 2:2, 3:3}
    if 4 in test:
        print(test[1])