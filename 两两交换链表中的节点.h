#pragma once
#include"��������.h"
//��Ŀ���������������еĽڵ�
//����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ�
//�нڵ㽻������

//����˼·����Ҫ���������ڵ��Ϊ�ڵ��飬�������ĸ��ڵ㣬���ǵĹ�ϵ��ͼ��
//          lastNode->formerNode->laterNode->nextNode
//          formerNode��ʾ�ڵ���ĵ�һ���ڵ㣬laterNode���ʾ�ڶ�����lastNode��nextNode����׸��
//          ����֮��Ľڵ�λ����ͼ��
//          lastNode->laterNode->formerNode->nextNode
//          �ɿ���������ָ���ϵ��Ҫ������������ֻ��Ҫ���θı�������ָ�򼴿�
//          ������һ��֮�󣬽������ṹ����Ƽ���



ListNode* swapPairs(ListNode* head) {
    if ((head == NULL) || (head->next == NULL))  return head;
    ListNode* dummy = new ListNode(0, head);//��������ڵ㣬ʹ��nextָ��ͷ���
    ListNode* lastNode = dummy;
    ListNode* formerNode = head;
    ListNode* laterNode = head->next;
    ListNode* nextNode = NULL;


    while (laterNode && formerNode)
    {
        nextNode = laterNode->next;

        //���нڵ㽻�����ı�����ָ��
        lastNode->next = laterNode;
        laterNode->next = formerNode;
        formerNode->next = nextNode;

        //���ṹ����ƽ�
        lastNode = formerNode;
        if ((nextNode == NULL) || (nextNode->next == NULL))  break;
        else {
            formerNode = nextNode;
            laterNode = nextNode->next;
        }
    }

    return dummy->next;
}