#pragma once
#include"��������.h"
#include<iostream>
#include<stack>
using namespace std;
typedef ListNode list_node;

//����ջ��ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(K)
//��¼�������
//ÿK��Ԫ����ջ
//��������㿪ʼ��Ϊÿ���ڵ㸳ջ����ֵ


//�ĸ��߽�ָ�룬ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(1)
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

        //�жϵ�ǰʣ��ڵ��Ƿ�K��
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

        //K�����ڸ��ڵ㷴ת
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