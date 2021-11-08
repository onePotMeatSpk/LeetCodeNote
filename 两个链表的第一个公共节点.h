#pragma once
#include<iostream>
#include<stack>
#include"��������.h"
using namespace std;

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
	if ((headA == NULL) || (headB == NULL))	return NULL;//³���Դ���

	stack<ListNode*> stackOfNodesA, stackOfNodesB;//�������A��B�����нڵ��ջ
	ListNode* p = NULL;//���������õ�ָ��

	//��A�нڵ�ȫ����ջ
	p = headA;
	while (p)
	{
		stackOfNodesA.push(p);
		p = p->next;
	}
	//��B�нڵ�ȫ����ջ	
	p = headB;
	while (p)
	{
		stackOfNodesB.push(p);
		p = p->next;
	}

	//ջ��Ԫ�����˵������δ������һ���ཻ��
	//ջ��Ԫ����������������1���Ѿ�������һ���ཻ�㣻2��������������ཻ��������������������˳�ѭ��������p���ɡ�
	//��ջ����˵�����Ѿ����϶������ջ������ϣ���󵯳���Ԫ�ؾ��ǵ�һ���ཻ�㡣
	p = NULL;
	while (stackOfNodesA.size() && stackOfNodesB.size() && (stackOfNodesA.top() == stackOfNodesB.top()) )
	{
		p = stackOfNodesA.top();
		stackOfNodesA.pop();
		stackOfNodesB.pop();
	}

	return p;
}
