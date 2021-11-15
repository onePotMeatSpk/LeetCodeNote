#pragma once
#include"单向链表.h"
using namespace std;

//思路
//反转前链表：pStartPre -> pStart -> ... -> pEnd -> pEndNext
//反转后链表：pStartPre -> pEnd -> ... -> pStart -> pEndNext
//进行反转操作前记录以上四个重要节点，随后对pStart到pEnd之间的节点进行遍历、挨个翻转，最后将pStartPre连接pEnd、pStart连接pEndNext
//注意：如果反转区间的左边界是head，则在最后进行重新连接时，需要重置head

ListNode* reverseBetween(ListNode* head, int left, int right) {
    //不需要反转的情况
    if (left >= right)
        return head;

    int len = 0;
    ListNode* p = head;
    ListNode* pStartPre = NULL;
    ListNode* pEndNext = NULL;
    ListNode* pStart = NULL;
    ListNode* pEnd = NULL;
    //取得链表长度
    while (p)
    {
        len++;

        //确定几个重要节点
        if (len == left - 1)
            pStartPre = p;
        if (len == left)
            pStart = p;
        if (len == right)
            pEnd = p;
        if (len == right + 1)
            pEndNext = p;

        p = p->next;
    }
    //如果left和right处在边界，则pStartPre和pEndNext需要特殊处理
    if (left == 1)
        pStartPre = NULL;
    if (right == len)
        pEndNext = NULL;
    //区间超出链表索引的情况
    if (len < left)
        return head;

    //初始化三个游标节点
    ListNode* pPre = pStartPre;
    ListNode* pNext = NULL;
    p = pStart;
    //遍历反转，直到pEndNext
    while (p != pEndNext)
    {
        pNext = p->next;
        p->next = pPre;
        pPre = p;
        p = pNext;
    }

    //将反转后的区间与前、后节点重新连接
    //pStartPre连接pEnd，pStart连接pEndNext
    //如果left为1，则需要重置head
    if (left == 1)
        head = pEnd;
    else
        pStartPre->next = pEnd;
    pStart->next = pEndNext;

    return head;
}