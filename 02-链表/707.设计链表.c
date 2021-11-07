/*
 * @lc app=leetcode.cn id=707 lang=c
 *
 * [707] 设计链表
 */
#include "stdio.h"
#include "stdlib.h"

// @lc code=start
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

// 3.指定位置节点读取值域
int myLinkedListGet(MyLinkedList *obj, int index)
{
    int i;
    MyLinkedList *temp = obj;
    for (i = 0; i <= index - 1; i++)
    {
        temp = temp->next;
    }
    printf("第%d个节点的值为%d\n", index, temp->value);
    return 0;
}

// 4.头插
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->value = val;

    MyLinkedList *temp = obj;
    node->next = temp->next;
    temp->next = node;
}

// 5.尾插
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->value = val;

    MyLinkedList *temp = obj;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
}

// 6.指定位置添加节点
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->value = val;

    int i;
    MyLinkedList *temp = obj;
    for (i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
}

// 7.指定位置删除节点
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    MyLinkedList *temp = obj;
    int i;
    for (i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    MyLinkedList *node = temp->next;
    temp->next = node->next;
    free(node);
    printf("删除第%d个节点后:\n", index);
}

// 8.删除链表
void myLinkedListFree(MyLinkedList *obj)
{
    MyLinkedList *temp = obj->next;
    MyLinkedList *node;
    printf("链表删除，空间释放：\n");
    while (temp != NULL)
    {
        printf("%d  >>  \n", temp->value);
        node = temp->next;
        free(temp);
        temp = node;
    }
}

// 9.遍历链表
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

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
// @lc code=end

int main(int argc, char **argv)
{
    int index = 3;
    MyLinkedList *head = myLinkedListCreate();
    myLinkedListAddAtHead(head, 1);
    myLinkedListAddAtHead(head, 1);
    myLinkedListAddAtHead(head, 1);
    myLinkedListAddAtHead(head, 1);
    myLinkedListAddAtTail(head, 5);
    myLinkedListAddAtIndex(head, 3, 3);
    display(head);
    myLinkedListGet(head, index);
    myLinkedListDeleteAtIndex(head, index);
    display(head);
    myLinkedListFree(head);

    return 0;
}