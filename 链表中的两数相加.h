#pragma once
#include<stack>
#include"��������.h"
#include<iostream>
using namespace std;


////����ջ+�����ӷ���ʱ�临�Ӷ�O(N)���ռ临�Ӷ�0(N)
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//    //³��
//    if (!l1) return l2;
//    if (!l2) return l1;
//
//    //s1��l1Ԫ�أ�s2��l2Ԫ�أ�s3��l3Ԫ��
//    stack<int> s1, s2, s3;
//    //upperΪ��λ��Ӳ����Ľ�λ��sumΪ��λ�ĺ�
//    int upper = 0, sum = 0;
//
//    //����l1��l2������Ԫ����ջ
//    ListNode* p = l1;
//    while (p)
//    {
//        s1.push(p->val);
//        p = p->next;
//    }
//    p = l2;
//    while (p)
//    {
//        s2.push(p->val);
//        p = p->next;
//    }
//
//    //��ͨ�Ĵ������
//    while (s1.size() || s2.size())
//    {
//        //��λ��
//        if (s1.empty())
//        {
//            sum = s2.top() + upper;
//            s2.pop();
//        }    
//        else if (s2.empty())
//        {
//            sum = s1.top() + upper;
//            s1.pop();
//        }
//        else
//        {
//            sum = s1.top() + s2.top() + upper;
//            s1.pop();
//            s2.pop();
//        }
//
//        //���λ
//        upper = sum / 10;
//        //����λ��ջ
//        s3.push(sum % 10);
//        
//    }
//
//    //�������յĽ�λ
//    if (upper)
//        s3.push(upper);
//
//    //�Ƚ�l3��ͷժ����
//    ListNode* head = new ListNode(s3.top());
//    s3.pop();
//    ListNode* pre = head;
//    ListNode* newNode = NULL;
//    
//    //����l3�����ڵ�
//    while (s3.size())
//    {
//        newNode = new ListNode(s3.top());
//        s3.pop();
//        pre->next = newNode;
//        pre = newNode;
//    }
//
//    return head;
//}

//��ת����+�����ӷ���ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(1)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	//³��

	//l1��l2��ת
	
	//���ߴ������

	//l1��l2��ת

	//return
}