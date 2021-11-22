#pragma once
#include<iostream>
#include<unordered_set>
#include"单向链表.h"
using namespace std;
typedef ListNode list_node;

////辅助哈希表+删除节点，时间复杂度O(N),空间复杂度O(N)
//list_node* remove_rep(list_node* head)
//{
//	if (head == NULL)
//		return NULL;
//	list_node* p = head;
//	list_node* pPre = NULL;
//	list_node* pNext = p->next;
//	unordered_set<int> s;
//	while (p)
//	{
//		if (s.find(p->val) == s.end())
//		{
//			s.insert(p->val);
//			pPre = p;
//		}
//
//		else
//			pPre->next = p->next;
//
//		p = p->next;
//	}
//
//	return head;
//}

//类似快排，时间复杂度O(N)，空间复杂度O(1)
list_node* remove_rep(list_node* head)
{
	list_node* pStart = head;
	list_node* pPre = pStart;
	list_node* p = NULL;
	while (pStart)
	{
		pPre = pStart;
		p = pStart->next;
		while (p)
		{
			if (p->val == pStart->val)
				pPre->next = p->next;
			else
				pPre = p;

			p = p->next;
		}

		pStart = pStart->next;
	}

	return head;
}



////排序+删除节点，时间复杂度O(N2),空间复杂度O(1)
////！！！会打乱节点顺序
//list_node* remove_rep(list_node* head)
//{
//	list_node* pStart = head;
//	list_node* pMin = head;
//	list_node* p = NULL;
//	int temp;
//	//排序
//	while (pStart)
//	{
//		pMin = pStart;
//		p = pStart->next;
//		while (p)
//		{
//			if (p->val < pMin->val)
//				pMin = p;
//			p = p->next;
//		}
//		if (pMin->val < pStart->val)
//		{
//			temp = pMin->val;
//			pMin->val = pStart->val;
//			pStart->val = temp;
//		}
//		pStart = pStart->next;
//	}
//
//	//删重复节点
//	list_node* pPre = head;
//	p = head->next;
//	while (p)
//	{
//		if (p->val == pPre->val)
//			pPre->next = p->next;
//		else
//			pPre = p;
//		p = p->next;
//	}
//	return head;
//}


