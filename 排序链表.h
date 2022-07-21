#pragma once
#include"单向链表.h"

//力扣148
//题目：排序链表
//题干：给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

//归并排序，原地
ListNode* sortList(ListNode* head) {
    if (!head || head->next == NULL)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = head;
    while (fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
    }
    prev->next = NULL;

    ListNode* newHead0 = sortList(head);
    ListNode* newHead1 = sortList(slow);

    ListNode* virtualHead = new ListNode();
    ListNode* cur = virtualHead;
    while (newHead0 && newHead1)
    {
        if (newHead0->val < newHead1->val)
        {
            cur->next = newHead0;
            newHead0 = newHead0->next;
        }
        else
        {
            cur->next = newHead1;
            newHead1 = newHead1->next;
        }
        cur = cur->next;
    }

    if (newHead0)
        cur->next = newHead0;
    if (newHead1)
        cur->next = newHead1;

    head = virtualHead->next;
    delete virtualHead;

    return head;
}