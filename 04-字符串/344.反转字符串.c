/*
 * @Author: Lucius
 * @Date: 2021-11-02 17:54:58
 * @LastEditTime: 2021-11-06 09:28:29
 * @LastEditors: Lucius
 * @Description:
 * @FilePath: \.leetcode\344.反转字符串.c
 * @lc app=leetcode.cn id=344 lang=c
 * [344] 反转字符串
 */
#include "stdio.h"
#include "string.h"

// @lc code=start
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b, *b = t;
}

void reverseString(char *s, int sSize)
{
    for (int left = 0, right = sSize - 1; left < right; ++left, --right)
    {
        swap(s + left, s + right);
    }
}
// @lc code=end

int main(int argc, char **argv)
{
    char s[] = "hello";
    printf("s before: %s\n", s);
    reverseString(s, strlen(s));
    printf("s: after%s\n", s);

    return 0;
}