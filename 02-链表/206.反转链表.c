/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
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
#if 1
MyLinkedList *reverseList(MyLinkedList *head)
{
    MyLinkedList *newhead = head->next;
    head->next = NULL;
    MyLinkedList *temp = newhead;

    while (newhead != NULL)
    {
        newhead = newhead->next;
        myLinkedListAddAtHead(head, temp->value);
        temp = newhead;
    }
}
#elif 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr)
    {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
#endif
// @lc code=end

int main(int argc, char **argv)
{
    MyLinkedList *head;
    head = myLinkedListCreate();
    myLinkedListAddAtHead(head, 1);
    myLinkedListAddAtHead(head, 2);
    myLinkedListAddAtHead(head, 3);
    myLinkedListAddAtHead(head, 4);
    myLinkedListAddAtHead(head, 5);
    display(head);
    reverseList(head);
    display(head);

    return 0;
}