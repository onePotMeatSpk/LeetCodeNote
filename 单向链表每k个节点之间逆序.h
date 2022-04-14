#pragma once
#include"单向链表.h"
#include<stack>
using namespace std;
typedef ListNode list_node;

////辅助栈+直接修改节点val，时间复杂度O(N)，空间复杂度O(K)
////该算法区间结构（中括号内即为区间）：[pStart->...]
//list_node* reverse_knode(list_node* head1, int K)
//{
//    //鲁棒
//    if (head1 == NULL)
//        return NULL;
//    if (K < 2)
//        return head1;
//
//    stack<int> s;
//    list_node* pStart = head1;
//    list_node* p = NULL;
//    int count = 1;
//    while (1)
//    {
//        p = pStart;
//        count = 1;
//
//        //区间元素入栈
//        while (count <= K)
//        {
//            //剩余元素不足K，则终结程序
//            if (p == NULL)    
//                return head1;
//            //各元素入栈
//            s.push(p->val);
//            p = p->next;
//            count++;
//        }
//
//        p = pStart;
//        //区间元素重置
//        while (!s.empty())
//        {
//            p->val = s.top();
//            s.pop();
//            p = p->next;
//        }
//        //重置区间起点
//        pStart = p;
//    }
//
//    return head1;
//}


//四个边界指针+反转链表，时间复杂度O(N)，空间复杂度O(1)
//该算法区间结构（中括号内即为区间）：pStart->[pSS->...->pEE]->pEnd
list_node* reverse_knode(list_node* head1, int K)
{
    //鲁棒
    if (head1 == NULL)
        return NULL;
    if (K < 2)
        return head1;

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

        pSS->next = pEnd;

        pStart = pSS;
    }
    return newHead;
}