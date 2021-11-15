#pragma once
#include"单向链表.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //特殊情形1：若链表仅有1节点，且删除倒1节点
    if (head->next == NULL && n == 1)
        return NULL;


    ListNode* pFast = head;
    ListNode* pSlow = head;
    ListNode* pPre = head;//前指针必须初始化为head，因为程序可能不会进入36行的循环
    ListNode* pNext = NULL;

    //快指针先走n步
    for (int i = 0; i < n; i++)
    {
        //快指针中途变NULL，说明链表节点不足k
        if (pFast == NULL)
            return head;

        pFast = pFast->next;
    }

    //快慢指针同时向后走
    //快指针到达NULL时，慢指针即为倒n节点
    while (pFast != NULL)
    {
        //记录下慢指针前后节点
        pPre = pSlow;
        pSlow = pSlow->next;
        pFast = pFast->next;
    }
    pNext = pSlow->next;//后指针必须在循环后记录，因为程序有可能不会进入循环

    //特殊情形2：删除节点为尾结点
    if (pSlow->next == NULL)
    {
        pPre->next = NULL;
        return head;
    }

    //特殊情形3：删除节点为头结点
    if (pSlow == head)
    {
        pSlow->next = NULL;
        return pNext;
    }

    //一般情形
    pSlow->next = NULL;
    pPre->next = pNext;
    return head;

}