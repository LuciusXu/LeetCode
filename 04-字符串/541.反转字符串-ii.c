/*
 * @Author: Lucius
 * @Date: 2021-11-03 10:40:15
 * @LastEditTime: 2021-11-04 13:44:25
 * @LastEditors: Lucius
 * @Description:
 * @FilePath: \.leetcode\541.反转字符串-ii.c
 * @lc app=leetcode.cn id=541 lang=c
 * [541] 反转字符串 II
 */
#include "stdio.h"
#include "string.h"

// @lc code=start
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b, *b = tmp;
}

void reverse(char *l, char *r)
{
    while (l < r)
    {
        swap(l++, --r);
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

char *reverseStr(char *s, int k)
{
    int n = strlen(s);
    for (int i = 0; i < n; i += 2 * k)
    {
        printf("i = %d, i+k = %d\n", i, i + k);
        reverse(&s[i], &s[min(i + k, n)]);
    }
    return s;
}
// @lc code=end

int main(int argc, char **argv)
{
    char s[] = "abcdefg";
    int k = 2;

    char *t = reverseStr(s, k);
    printf("s: %s\n", t);

    return 0;
}