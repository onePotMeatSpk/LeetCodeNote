#pragma once
#include"单向链表.h"
using namespace std;
typedef ListNode list_node;

list_node* list_partition(list_node* head, int pivot)
{
    //////在下面完成代码
    //鲁棒
    if (!head)    return head;

    //本体思路：
    //用以下六指针记录链表关键节点，他们将链表分为三段，均初始化为NULL
    //随遍历更新指针（主要是拓展各段右边界）
    //最后指定新的head，并将三段连接起来
    //s1：小于段左边界，s2：小于段右边界
    //e1：等于段左边界，e2：等于段右边界
    //s1：大于段左边界，s2：大于段右边界
    list_node* s1 = NULL;
    list_node* s2 = NULL;
    list_node* e1 = NULL;
    list_node* e2 = NULL;
    list_node* l1 = NULL;
    list_node* l2 = NULL;
    //p为遍历指针
    list_node* p = head;

    while (p)
    {
        //当前值小于pivot
        if (p->val < pivot)
        {
            //小于段仍为空
            if (!s1)
            {
                s1 = p;
                s2 = p;
            }
            //小于段不为空
            else
            {
                s2->next = p;
                s2 = s2->next;
            }
        }
        //当前值等于pivot
        else if (p->val == pivot)
        {
            if (!e1)
            {
                e1 = p;
                e2 = p;
            }
            else
            {
                e2->next = p;
                e2 = e2->next;
            }
        }
        //当前值大于pivot
        else
        {
            if (!l1)
            {
                l1 = p;
                l2 = p;
            }
            else
            {
                l2->next = p;
                l2 = l2->next;
            }
        }

        p = p->next;
    }
    if (s2)
        s2->next = NULL;
    if (e2)
        e2->next = NULL;
    if (l2)
        l2->next = NULL;

    if (s1)
    {
        head = s1;
        if (e1)
        {
            s2->next = e1;
            if (l1)
                e2->next = l1;
        }
        else if (l1)
            s2->next = l1;
    }
    else if (e1)
    {
        head = e1;
        if (l1)
            e2->next = l1;
    }
    else
        head = l1;

    p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }

    return head;
}