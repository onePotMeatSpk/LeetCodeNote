#pragma once
#include"单向链表.h"
#include<deque>
using namespace std;
//力扣234
//题目：回文链表
//题目描述：给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。



//方法1：用数组记录各节点值，然后检查数组是否回文
//O(N),O(N)
bool isPalindrome(ListNode* head) {
    deque<int> d;
    ListNode* cur = head;

    while (cur)
    {
        d.push_back(cur->val);
        cur = cur->next;
    }

    while (!d.empty())
    {
        if (d.size() == 1)   return 1;
        if (d.front() != d.back())   return 0;
        d.pop_front();
        d.pop_back();
    }

    return 1;
}

//方法2：反转后半段链表，然后比较前后半段链表是否相同
//O(N),O(1)

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
bool isPalindrome(ListNode* head) {
    //统计链表长度
    int len = 0;
    ListNode* cur = head;
    while (cur)
    {
        len++;
        cur = cur->next;
    }

    //反转后半段链表
    cur = head;
    for (int i = 0; i < (len % 2 ? len / 2 : len / 2 - 1); i++)
        cur = cur->next;
    cur->next = reverseList(cur->next);

    //比较前后半段是否相同
    cur = cur->next;
    while (cur)
    {
        if (cur->val != head->val)   return 0;
        cur = cur->next;
        head = head->next;
    }

    return 1;
}