#pragma once
#include"单向链表.h"
#include<iostream>
#include<stack>
using namespace std;
typedef ListNode list_node;

//辅助栈，时间复杂度O(N)，空间复杂度O(K)
//记录区间起点
//每K个元素入栈
//从区间起点开始，为每个节点赋栈顶的值


//四个边界指针，时间复杂度O(N)，空间复杂度O(1)
list_node* reverse_knode(list_node* head1, int K)
{
    list_node* pStart = NULL;
    list_node* pEnd = NULL;
    list_node* pSS = NULL;
    list_node* pEE = NULL;
    list_node* newHead = head1;
    list_node* p = NULL;
    list_node* pPre = NULL;
    list_node* pNext = NULL;
    int count = 0;

    while (1)
    {
        
        if (pStart == NULL)
            p = head1;
        else
            p = pStart->next;
        count = 1;

        //判断当前剩余节点是否够K个
        while (count <= K)
        {
            if (p == NULL)
                return newHead;
            if (count < K)
            {
                p = p->next;
                count++;
            }
            else
            {
                pEE = p;
                pEnd = p->next;
                break;
            }
        }

        if (pStart == NULL)
            p = head1;
        else
            p = pStart->next;
        count = 1;
        pSS = p;
        pPre = NULL;

        //K区间内各节点反转
        while (count <= K)
        {
            pNext = p->next;
            p->next = pPre;
            pPre = p;
            p = pNext;
            count++;
        }

        if (pStart == NULL)
            newHead = pEE;
        else
            pStart->next = pEE;
        if (pSS == NULL)
            return newHead;
        else
            pSS->next = pEnd;

        pStart = pSS;
    }
    return newHead;
}