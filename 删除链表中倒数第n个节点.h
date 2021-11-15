#pragma once
#include"��������.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //��������1�����������1�ڵ㣬��ɾ����1�ڵ�
    if (head->next == NULL && n == 1)
        return NULL;


    ListNode* pFast = head;
    ListNode* pSlow = head;
    ListNode* pPre = head;//ǰָ������ʼ��Ϊhead����Ϊ������ܲ������36�е�ѭ��
    ListNode* pNext = NULL;

    //��ָ������n��
    for (int i = 0; i < n; i++)
    {
        //��ָ����;��NULL��˵������ڵ㲻��k
        if (pFast == NULL)
            return head;

        pFast = pFast->next;
    }

    //����ָ��ͬʱ�����
    //��ָ�뵽��NULLʱ����ָ�뼴Ϊ��n�ڵ�
    while (pFast != NULL)
    {
        //��¼����ָ��ǰ��ڵ�
        pPre = pSlow;
        pSlow = pSlow->next;
        pFast = pFast->next;
    }
    pNext = pSlow->next;//��ָ�������ѭ�����¼����Ϊ�����п��ܲ������ѭ��

    //��������2��ɾ���ڵ�Ϊβ���
    if (pSlow->next == NULL)
    {
        pPre->next = NULL;
        return head;
    }

    //��������3��ɾ���ڵ�Ϊͷ���
    if (pSlow == head)
    {
        pSlow->next = NULL;
        return pNext;
    }

    //һ������
    pSlow->next = NULL;
    pPre->next = pNext;
    return head;

}