#pragma once
#include"��������.h"
using namespace std;
//����21
//��Ŀ���ϲ�������������
//��Ŀ��������������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 

//���ƹ鲢����ĺϲ�����
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2)    return list1 ? list1 : list2;

    ListNode* cur1 = list1;
    ListNode* cur2 = list2;
    ListNode* head = new ListNode();
    ListNode* cur = head;

    while (cur1 && cur2)
    {
        ListNode* temp = NULL;
        if (cur1->val < cur2->val)
        {
            temp = cur1;
            cur1 = cur1->next;
        }
        else
        {
            temp = cur2;
            cur2 = cur2->next;
        }
        cur->next = temp;
        cur = cur->next;
    }

    if (cur1)    cur->next = cur1;
    if (cur2)    cur->next = cur2;

    return head->next;
}