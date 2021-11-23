#pragma once
#include<iostream>
#include"单向链表.h"
using namespace std;

typedef ListNode list_node;

//快慢指针
list_node* relocate(list_node* head)
{
	list_node* p = head;
	int sum = 0;
	while (p)
	{
		p = p->next;
		sum++;
	}

	p = head;
	for (int i = 1; i < sum / 2; i++)
		p = p->next;

	list_node* pLeft = head;
	list_node* pRight = p->next;
	p->next = NULL;

	list_node* pre = pLeft;
	pLeft = pLeft->next;
	while (pLeft)
	{
		pre->next = pRight;
		pRight = pRight->next;
		pre = pre->next;

		pre->next = pLeft;
		pLeft = pLeft->next;
		pre = pre->next;
	}

	while (pRight)
	{
		pre->next = pRight;
		pRight = pRight->next;
		pre = pre->next;
	}

	return head;
}