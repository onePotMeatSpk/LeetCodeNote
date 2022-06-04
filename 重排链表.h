#pragma once
#include"��������.h"
using namespace std;

//����143
//��Ŀ����������
//��Ŀ����������һ�������� L ��ͷ�ڵ� head �������� L ��ʾΪ��
			//L0 �� L1 �� �� �� Ln - 1 �� Ln
			//�뽫���������к��Ϊ��
			//
			//L0 �� Ln �� L1 �� Ln - 1 �� L2 �� Ln - 2 �� ��
			//����ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

//ͳ�������Ⱥ���
int lenOfList(ListNode* head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

//�з����������з�����Ϊhead1��head2
void cutList(ListNode* head, int len, ListNode*& head1, ListNode*& head2)
{
    head1 = head;//ȷ��head1
    //lenΪżʱ������ͬ����Ϊ��ʱ��ǰ�߳�1
    for (int i = 0; i < (len % 2 ? len / 2 + 1 : len / 2); i++)
        head = head->next;  
    head2 = head;//ȷ��head2

    //��head1β����ΪNULL
    head = head1;
    while (head->next != head2)
        head = head->next;
    head->next = NULL;
}

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
void reorderList(ListNode* head) {
    //ͳ��������
    int len = lenOfList(head);

    //�������Ϊ����: head1��head2
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    cutList(head, len, head1, head2);

    //��ת����2
    head2 = reverseList(head2);

    //�ϲ�����
    while (head2)
    {
        ListNode* next1 = head1->next;
        ListNode* next2 = head2->next;

        if (head1->next)
        {
            head2->next = head1->next;
            head1->next = head2;
        }
        else
            head1->next = head2;

        head1 = next1;
        head2 = next2;
    }
}
