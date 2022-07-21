#pragma once
#include"��������.h"

//����148
//��Ŀ����������
//��ɣ����������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��

//�鲢����ԭ��
ListNode* sortList(ListNode* head) {
    if (!head || head->next == NULL)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = head;
    while (fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
    }
    prev->next = NULL;

    ListNode* newHead0 = sortList(head);
    ListNode* newHead1 = sortList(slow);

    ListNode* virtualHead = new ListNode();
    ListNode* cur = virtualHead;
    while (newHead0 && newHead1)
    {
        if (newHead0->val < newHead1->val)
        {
            cur->next = newHead0;
            newHead0 = newHead0->next;
        }
        else
        {
            cur->next = newHead1;
            newHead1 = newHead1->next;
        }
        cur = cur->next;
    }

    if (newHead0)
        cur->next = newHead0;
    if (newHead1)
        cur->next = newHead1;

    head = virtualHead->next;
    delete virtualHead;

    return head;
}