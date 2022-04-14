#pragma once
#include"单向链表.h"
using namespace std;

typedef ListNode list_node;

//类似快排的合并环节
list_node* merge_list(list_node* head1, list_node* head2)
{
	//鲁棒
	if (!head1)
		return head2;
	if (!head2)
		return head1;

	list_node* p1 = head1;
	list_node* p2 = head2;
	list_node* newHead = NULL;
	if (p1->val <= p2->val)
	{
		newHead = p1;
		p1 = p1->next;
	}
	else
	{
		newHead = p2;
		p2 = p2->next;
	}

	list_node* pre = newHead;
	while (p1 && p2)
	{
		if (p1->val <= p2->val)
		{
			pre->next = p1;
			pre = p1;
			p1 = p1->next;
		}
		else
		{
			pre->next = p2;
			pre = p2;
			p2 = p2->next;
		}
	}

	while (p1)
	{
		pre->next = p1;
		pre = p1;
		p1 = p1->next;
	}

	while (p2)
	{
		pre->next = p2;
		pre = p2;
		p2 = p2->next;
	}

	return newHead;
}