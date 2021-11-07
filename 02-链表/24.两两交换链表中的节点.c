/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
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
MyLinkedList *swapPairs(MyLinkedList *head)
{
    MyLinkedList *temp = head;
    while (temp->next != NULL && temp->next->next != NULL)
    {
        MyLinkedList *node1 = temp->next;
        MyLinkedList *node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return head;
}
#elif 1
struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode *temp = &dummyHead;
    while (temp->next != NULL && temp->next->next != NULL)
    {
        struct ListNode *node1 = temp->next;
        struct ListNode *node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead.next;
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
    display(head);
    head = swapPairs(head);
    display(head);

    return 0;
}