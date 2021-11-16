#pragma once
#include"��������.h"
using namespace std;
typedef ListNode list_node;

list_node* list_partition(list_node* head, int pivot)
{
    //////��������ɴ���
    //³��
    if (!head)    return head;

    //����˼·��
    //��������ָ���¼����ؼ��ڵ㣬���ǽ������Ϊ���Σ�����ʼ��ΪNULL
    //���������ָ�루��Ҫ����չ�����ұ߽磩
    //���ָ���µ�head������������������
    //s1��С�ڶ���߽磬s2��С�ڶ��ұ߽�
    //e1�����ڶ���߽磬e2�����ڶ��ұ߽�
    //s1�����ڶ���߽磬s2�����ڶ��ұ߽�
    list_node* s1 = NULL;
    list_node* s2 = NULL;
    list_node* e1 = NULL;
    list_node* e2 = NULL;
    list_node* l1 = NULL;
    list_node* l2 = NULL;
    //pΪ����ָ��
    list_node* p = head;

    while (p)
    {
        //��ǰֵС��pivot
        if (p->val < pivot)
        {
            //С�ڶ���Ϊ��
            if (!s1)
            {
                s1 = p;
                s2 = p;
            }
            //С�ڶβ�Ϊ��
            else
            {
                s2->next = p;
                s2 = s2->next;
            }
        }
        //��ǰֵ����pivot
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
        //��ǰֵ����pivot
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