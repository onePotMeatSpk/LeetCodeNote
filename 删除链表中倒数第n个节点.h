#pragma once
#include"单向链表.h"

ListNode* removeNthFromEnd(ListNode * head, int n) {
    //鲁棒
    if (n <= 0)
        return head;

    ListNode* pFast = head;//快指针
    ListNode* pSlow = head;//慢指针
    ListNode* dummy = new ListNode(0, head);//虚拟节点，用于指向头结点
    ListNode* prev = dummy;//删除节点的前面的节点

    //快指针先走n步
    for (int i = 0; i < n; i++)
    {
        if (pFast == NULL)//没走完n步就NULL了，说明链表里面不够n个节点
            return head;
        pFast = pFast->next;
    }

    //快慢指针一起走，直到快指针NULL
    while (pFast)
    {
        pFast = pFast->next;
        prev = pSlow;
        pSlow = pSlow->next;
    }
    prev->next = pSlow->next;
    delete(pSlow);
    return dummy->next;
}
