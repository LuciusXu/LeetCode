/*
 * @Author: Lucius
 * @Date: 2021-11-08 10:52:20
 * @LastEditTime: 2021-11-08 18:16:52
 * @LastEditors: Lucius
 * @Description:
 * @FilePath: \.leetcode\26.删除有序数组中的重复项.c
 * @lc app=leetcode.cn id=26 lang=c
 * [26] 删除有序数组中的重复项
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

// @lc code=start
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }
    int fast = 1, slow = 1;
    while (fast < numsSize)
    {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}
// @lc code=end

int main(int argc, char **argv)
{
    int nums[] = {1, 1, 2};
    int numsSize = sizeof(nums) / sizeof(*nums);
    int result = 0;

    result = removeDuplicates(nums, numsSize);
    printf("result = %d\n", result);
    for (int i = 0; i < result; i++)
    {
        printf("%d\n", nums[i]);
    }

    return 0;
}