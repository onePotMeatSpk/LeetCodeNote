#pragma once
#include"µ¥ÏòÁ´±í.h"
using namespace std;
typedef ListNode list_node;

list_node* insert_num(list_node* head, int num)
{
	//Â³°ô
	if (!head)
	{
		head = new list_node(num);
		head->next = head;
		return head;
	}

	list_node* pre = head;
	list_node* cur = head->next;

	while (1)
	{
		if ((num >= pre->val) && (num <= cur->val))
		{
			list_node* newNode = new list_node(num);
			pre->next = newNode;
			newNode->next = cur;
			return head;
		}

		if (cur == head)
		{
			list_node* newNode = new list_node(num);
			pre->next = newNode;
			newNode->next = head;
			if (num < head->val)
				return newNode;
			
			if (num > pre->val)
				return head;
		}

		pre = cur;
		cur = cur->next;
	}

	return head;
}