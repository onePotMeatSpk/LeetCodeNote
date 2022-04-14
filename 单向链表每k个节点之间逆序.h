#pragma once
#include"��������.h"
#include<stack>
using namespace std;
typedef ListNode list_node;

////����ջ+ֱ���޸Ľڵ�val��ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(K)
////���㷨����ṹ���������ڼ�Ϊ���䣩��[pStart->...]
//list_node* reverse_knode(list_node* head1, int K)
//{
//    //³��
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
//        //����Ԫ����ջ
//        while (count <= K)
//        {
//            //ʣ��Ԫ�ز���K�����ս����
//            if (p == NULL)    
//                return head1;
//            //��Ԫ����ջ
//            s.push(p->val);
//            p = p->next;
//            count++;
//        }
//
//        p = pStart;
//        //����Ԫ������
//        while (!s.empty())
//        {
//            p->val = s.top();
//            s.pop();
//            p = p->next;
//        }
//        //�����������
//        pStart = p;
//    }
//
//    return head1;
//}


//�ĸ��߽�ָ��+��ת����ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(1)
//���㷨����ṹ���������ڼ�Ϊ���䣩��pStart->[pSS->...->pEE]->pEnd
list_node* reverse_knode(list_node* head1, int K)
{
    //³��
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

        pSS->next = pEnd;

        pStart = pSS;
    }
    return newHead;
}