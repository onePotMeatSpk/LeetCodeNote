#pragma once
#include"��������.h"

ListNode* removeNthFromEnd(ListNode * head, int n) {
    //³��
    if (n <= 0)
        return head;

    ListNode* pFast = head;//��ָ��
    ListNode* pSlow = head;//��ָ��
    ListNode* dummy = new ListNode(0, head);//����ڵ㣬����ָ��ͷ���
    ListNode* prev = dummy;//ɾ���ڵ��ǰ��Ľڵ�

    //��ָ������n��
    for (int i = 0; i < n; i++)
    {
        if (pFast == NULL)//û����n����NULL�ˣ�˵���������治��n���ڵ�
            return head;
        pFast = pFast->next;
    }

    //����ָ��һ���ߣ�ֱ����ָ��NULL
    while (pFast)
    {
        pFast = pFast->next;
        prev = pSlow;
        pSlow = pSlow->next;
    }
    prev->next = pSlow->next;
    delete(pSlow);
    return dummy->next;
}
