/*
 * @Author: Lucius
 * @Date: 2021-11-07 18:49:37
 * @LastEditTime: 2021-11-07 18:52:53
 * @LastEditors: Lucius
 * @Description: 
 * @FilePath: \.leetcode\LeetCode\04-字符串\05.替换空格[剑指Offer].c
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *replaceSpace(char *s)
{
    char *ans = (char *)malloc(sizeof(char) * strlen(s) * 3 + 1);
    int i = 0;
    while (*s)
    {
        if (*s == ' ')
        {
            ans[i++] = '%';
            ans[i++] = '2';
            ans[i++] = '0';
        }
        else
        {
            ans[i++] = *s;
        }
        s++;
    }
    ans[i] = 0;
    return ans;
}

int main(int argc, char **argv)
{
    char s[] = "We are happy.";
    char *t;

    t = replaceSpace(s);
    printf("%s\n", t);

    return 0;
}