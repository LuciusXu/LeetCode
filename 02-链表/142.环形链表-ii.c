/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
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

// 4.环状
void myLinkedListAddAtTail(MyLinkedList *obj)
{
    MyLinkedList *temp = obj;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = obj->next->next;
}

// 5.遍历链表
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
MyLinkedList *detectCycle(MyLinkedList *head)
{
    MyLinkedList *slow = head, *fast = head;
    while (fast != NULL)
    {
        slow = slow->next;
        if (fast->next == NULL)
        {
            return NULL;
        }
        fast = fast->next->next;
        if (fast == slow)
        {
            MyLinkedList *ptr = head;
            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;
}
#elif 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL)
    {
        slow = slow->next;
        if (fast->next == NULL)
        {
            return NULL;
        }
        fast = fast->next->next;
        if (fast == slow)
        {
            struct ListNode *ptr = head;
            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;
}
#endif
// @lc code=end

int main(int argc, char **argv)
{
    MyLinkedList *head = myLinkedListCreate();
    myLinkedListAddAtHead(head, -4);
    myLinkedListAddAtHead(head, 0);
    myLinkedListAddAtHead(head, 2);
    myLinkedListAddAtHead(head, 3);
    display(head);
    myLinkedListAddAtTail(head);
    // display(head);

    return 0;
}