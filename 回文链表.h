#pragma once
#include"��������.h"
#include<deque>
using namespace std;
//����234
//��Ŀ����������
//��Ŀ����������һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ������������ǣ����� true �����򣬷��� false ��



//����1���������¼���ڵ�ֵ��Ȼ���������Ƿ����
//O(N),O(N)
bool isPalindrome(ListNode* head) {
    deque<int> d;
    ListNode* cur = head;

    while (cur)
    {
        d.push_back(cur->val);
        cur = cur->next;
    }

    while (!d.empty())
    {
        if (d.size() == 1)   return 1;
        if (d.front() != d.back())   return 0;
        d.pop_front();
        d.pop_back();
    }

    return 1;
}

//����2����ת��������Ȼ��Ƚ�ǰ���������Ƿ���ͬ
//O(N),O(1)

//��ת������
ListNode* reverseList(ListNode* head, ListNode* prev = NULL)
{
    if (head == NULL)    return NULL;

    if (head->next == NULL)
    {
        head->next = prev;
        return head;
    }

    ListNode* ret = reverseList(head->next, head);
    head->next = prev;
    return ret;
}
//������
bool isPalindrome(ListNode* head) {
    //ͳ��������
    int len = 0;
    ListNode* cur = head;
    while (cur)
    {
        len++;
        cur = cur->next;
    }

    //��ת��������
    cur = head;
    for (int i = 0; i < (len % 2 ? len / 2 : len / 2 - 1); i++)
        cur = cur->next;
    cur->next = reverseList(cur->next);

    //�Ƚ�ǰ�����Ƿ���ͬ
    cur = cur->next;
    while (cur)
    {
        if (cur->val != head->val)   return 0;
        cur = cur->next;
        head = head->next;
    }

    return 1;
}