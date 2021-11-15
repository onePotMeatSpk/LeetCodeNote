#pragma once
#include"��������.h"
using namespace std;

//˼·
//��תǰ����pStartPre -> pStart -> ... -> pEnd -> pEndNext
//��ת������pStartPre -> pEnd -> ... -> pStart -> pEndNext
//���з�ת����ǰ��¼�����ĸ���Ҫ�ڵ㣬����pStart��pEnd֮��Ľڵ���б�����������ת�����pStartPre����pEnd��pStart����pEndNext
//ע�⣺�����ת�������߽���head��������������������ʱ����Ҫ����head

ListNode* reverseBetween(ListNode* head, int left, int right) {
    //����Ҫ��ת�����
    if (left >= right)
        return head;

    int len = 0;
    ListNode* p = head;
    ListNode* pStartPre = NULL;
    ListNode* pEndNext = NULL;
    ListNode* pStart = NULL;
    ListNode* pEnd = NULL;
    //ȡ��������
    while (p)
    {
        len++;

        //ȷ��������Ҫ�ڵ�
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
    //���left��right���ڱ߽磬��pStartPre��pEndNext��Ҫ���⴦��
    if (left == 1)
        pStartPre = NULL;
    if (right == len)
        pEndNext = NULL;
    //���䳬���������������
    if (len < left)
        return head;

    //��ʼ�������α�ڵ�
    ListNode* pPre = pStartPre;
    ListNode* pNext = NULL;
    p = pStart;
    //������ת��ֱ��pEndNext
    while (p != pEndNext)
    {
        pNext = p->next;
        p->next = pPre;
        pPre = p;
        p = pNext;
    }

    //����ת���������ǰ����ڵ���������
    //pStartPre����pEnd��pStart����pEndNext
    //���leftΪ1������Ҫ����head
    if (left == 1)
        head = pEnd;
    else
        pStartPre->next = pEnd;
    pStart->next = pEndNext;

    return head;
}