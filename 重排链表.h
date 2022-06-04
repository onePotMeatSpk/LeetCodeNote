#pragma once
#include"单向链表.h"
using namespace std;

//力扣143
//题目：重排链表
//题目描述：给定一个单链表 L 的头节点 head ，单链表 L 表示为：
			//L0 → L1 → … → Ln - 1 → Ln
			//请将其重新排列后变为：
			//
			//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
			//不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

//统计链表长度函数
int lenOfList(ListNode* head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

//中分链表函数，中分链表为head1、head2
void cutList(ListNode* head, int len, ListNode*& head1, ListNode*& head2)
{
    head1 = head;//确定head1
    //len为偶时，两者同长；为奇时，前者长1
    for (int i = 0; i < (len % 2 ? len / 2 + 1 : len / 2); i++)
        head = head->next;  
    head2 = head;//确定head2

    //将head1尾部设为NULL
    head = head1;
    while (head->next != head2)
        head = head->next;
    head->next = NULL;
}

//反转链表函数
ListNode* reverseList(ListNode* head, ListNode* prev = NULL)
{
    if (head == NULL)    return NULL;
    if (head->next == NULL)
    {
        head->next = prev;
        return head;
    }

    ListNode* ret = reverseList(head->next, head);
    head->next = prev;
    return ret;
}

//主函数
void reorderList(ListNode* head) {
    //统计链表长度
    int len = lenOfList(head);

    //将链表分为两段: head1和head2
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    cutList(head, len, head1, head2);

    //反转链表2
    head2 = reverseList(head2);

    //合并两段
    while (head2)
    {
        ListNode* next1 = head1->next;
        ListNode* next2 = head2->next;

        if (head1->next)
        {
            head2->next = head1->next;
            head1->next = head2;
        }
        else
            head1->next = head2;

        head1 = next1;
        head2 = next2;
    }
}
