#pragma once
#include"单向链表.h"
using namespace std;
//力扣21
//题目：合并两个有序链表
//题目描述：将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

//类似归并排序的合并环节
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2)    return list1 ? list1 : list2;

    ListNode* cur1 = list1;
    ListNode* cur2 = list2;
    ListNode* head = new ListNode();
    ListNode* cur = head;

    while (cur1 && cur2)
    {
        ListNode* temp = NULL;
        if (cur1->val < cur2->val)
        {
            temp = cur1;
            cur1 = cur1->next;
        }
        else
        {
            temp = cur2;
            cur2 = cur2->next;
        }
        cur->next = temp;
        cur = cur->next;
    }

    if (cur1)    cur->next = cur1;
    if (cur2)    cur->next = cur2;

    return head->next;
}