/*

https://leetcode.com/problems/two-sum/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 */

#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// int *twoSum(int *nums, int numsSize, int target, int *returnSize)
// {
//     int i, j;
//     int *ret = calloc(2, sizeof(int));
//     for (i = 0; i < numsSize; i++)
//     {
//         int key = target - nums[i];
//         for (j = i + 1; j < numsSize; j++)
//             if (nums[j] == key)
//             {
//                 ret[0] = i;
//                 ret[1] = j;
//             }
//     }
//     *returnSize = 2;
//     return ret;
// }

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *index = (int *)malloc(sizeof(int) * 2);
    if (NULL == index)
        return NULL;
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                index[0] = i;
                index[1] = j;
                return index;
            }
        }
    }
    return index;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *i = twoSum(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    printf("%d %d\n", i[0], i[1]);
    free(i);
    return 0;
}