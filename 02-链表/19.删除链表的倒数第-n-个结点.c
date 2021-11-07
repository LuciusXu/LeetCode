/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include "stdio.h"
#include "stdlib.h"

// 1.单向链表节点申明
typedef struct mylinkedlist
{
    int value;
    struct mylinkedlist *next;
} MyLinkedList;

// 2.链表初始化
MyLinkedList *myLinkedListCreate(void)
{
    MyLinkedList *head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

// 3.头插
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->value = val;

    MyLinkedList *temp = obj;
    node->next = temp->next;
    temp->next = node;
}

// 4.遍历链表
void display(MyLinkedList *head)
{
    MyLinkedList *temp = head->next;
    while (temp != NULL)
    {
        printf("%d  >>  ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#if 1
MyLinkedList *removeNthFromEnd(MyLinkedList *head, int n)
{
    MyLinkedList *first = head->next;
    MyLinkedList *second = head;
    for (int i = 0; i < n; ++i)
    {
        first = first->next;
    }
    while (first)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    MyLinkedList *ans = head->next;
    return head;
}
#elif 1
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0, dummy->next = head;
    struct ListNode *first = head;
    struct ListNode *second = dummy;
    for (int i = 0; i < n; ++i)
    {
        first = first->next;
    }
    while (first)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    struct ListNode *ans = dummy->next;
    free(dummy);
    return ans;
}
#endif
// @lc code=end

int main(int argc, char **argv)
{
    MyLinkedList *head;
    int n = 3;
    head = myLinkedListCreate();
    myLinkedListAddAtHead(head, 5);
    myLinkedListAddAtHead(head, 4);
    myLinkedListAddAtHead(head, 3);
    myLinkedListAddAtHead(head, 2);
    myLinkedListAddAtHead(head, 1);
    display(head);
    head = removeNthFromEnd(head, n);
    display(head);

    return 0;
}