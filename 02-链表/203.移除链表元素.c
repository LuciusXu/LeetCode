/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 */
#include "stdio.h"
#include "stdlib.h"

// 1、单向链表节点声明
typedef struct listnode
{
    int val;
    struct listnode *next;
} ListNode;

// 2、链表初始化
ListNode *init_link(void)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    return head;
}

// 3、插入某个数据到某个位置
void insert_link(ListNode *head, int elem, int add)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = elem;

    int i;
    ListNode *temp = head;
    for (i = 0; i < add - 1; i++)
    {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
}

// 4、遍历链表
void display(ListNode *head)
{
    ListNode *temp = head->next;
    while (temp != NULL)
    {
        printf("%d  >>  ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// @lc code=start
#if 1
// 5、删除包含指定数据域的节点
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummyHead = malloc(sizeof(ListNode));
    dummyHead->next = head;
    ListNode *temp = dummyHead;
    while (temp->next != NULL)
    {
        if (temp->next->val == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return dummyHead->next;
}
#elif 1
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode *temp = dummyHead;
    while (temp->next != NULL)
    {
        if (temp->next->val == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return dummyHead->next;
}
#endif
// @lc code=end

int main(int argc, char **argv)
{
    int val = 6;
    ListNode *head = init_link();
    insert_link(head, 6, 1);
    insert_link(head, 5, 1);
    insert_link(head, 4, 1);
    insert_link(head, 3, 1);
    insert_link(head, 6, 1);
    insert_link(head, 2, 1);
    insert_link(head, 1, 1);
    display(head);

    head = removeElements(head, val);
    display(head);

    return 0;
}