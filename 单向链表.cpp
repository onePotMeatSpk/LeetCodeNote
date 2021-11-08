#include"单向链表.h"
using namespace std;

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


