#pragma once
#include<vector>
using namespace std;

//单向链表结构体
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL) {};
	ListNode(int x) : val(x), next(NULL) {};
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//创建单向链表函数（输入一个vector）
//返回链表头节点指针
ListNode* createList(vector<int> v)
{
	if (v.empty())	return NULL;
	ListNode* headNode = new ListNode(*v.begin());
	ListNode* p = headNode;
	for (vector<int>::iterator it = v.begin() + 1; it != v.end(); it++)
	{
		p->next = new ListNode(*it);
		p = p->next;
	}
	return headNode;
}

//打印单向链表函数（输入一个链表头）
void printList(ListNode* head)
{
	ListNode* p = head;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}