/*
 * @Author: Lucius
 * @Date: 2021-11-05 11:00:14
 * @LastEditTime: 2021-11-06 11:07:09
 * @LastEditors: Lucius
 * @Description:
 * @FilePath: \.leetcode\151.翻转字符串里的单词.c
 * @lc app=leetcode.cn id=151 lang=c
 * [151] 翻转字符串里的单词
 */
#include "stdio.h"
#include "string.h"

// @lc code=start
/**
 * @description: 反转指定字符串的指定长度
 * @param {char} *s
 * @param {int} start
 * @param {int} end
 * @return {*}
 */
void reverseString(char *s, int start, int end)
{
    printf("s: %s\n", s);
    end -= 1;
    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char *reverseWords(char *s)
{
    int len = strlen(s);
    printf("len = %d\n", len);
    reverseString(s, 0, len); //反转整个字符串
    int idx = 0;
    for (int start = 0; start < len; start++)
    {
        if (s[start] != ' ')
        {
            if (idx != 0) //给每个反转后的单词添加空格
            {
                s[idx++] = ' ';
            }
            int end = start;
            while (end < len && s[end] != ' ') //计算出每个单词的长度
            {
                s[idx++] = s[end++];
            }
            printf("idx = %d, start = %d, end = %d\n", idx, start, end);
            reverseString(s, idx - (end - start), idx); //逐个反转单词
            start = end;
        }
    }
    s[idx] = '\0';
    return s;
}
// @lc code=end

int main(int argc, char **argv)
{
    char s[] = "the sky is blue";
    char *t;
    t = reverseWords(s);
    printf("%s\n", t);
    return 0;
}
