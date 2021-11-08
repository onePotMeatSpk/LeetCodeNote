#pragma once
#include<iostream>
#include<stack>
#include"单向链表.h"
using namespace std;

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
	if ((headA == NULL) || (headB == NULL))	return NULL;//鲁棒性处理

	stack<ListNode*> stackOfNodesA, stackOfNodesB;//创建存放A、B链表中节点的栈
	ListNode* p = NULL;//创建遍历用的指针

	//将A中节点全部入栈
	p = headA;
	while (p)
	{
		stackOfNodesA.push(p);
		p = p->next;
	}
	//将B中节点全部入栈	
	p = headB;
	while (p)
	{
		stackOfNodesB.push(p);
		p = p->next;
	}

	//栈顶元素相等说明：还未经过第一个相交点
	//栈顶元素相等有两种情况：1、已经经过第一个相交点；2、两链表根本不相交。不管是哪种情况，都退出循环，返回p即可。
	//有栈空了说明：已经将较短链表的栈弹出完毕，最后弹出的元素就是第一个相交点。
	p = NULL;
	while (stackOfNodesA.size() && stackOfNodesB.size() && (stackOfNodesA.top() == stackOfNodesB.top()) )
	{
		p = stackOfNodesA.top();
		stackOfNodesA.pop();
		stackOfNodesB.pop();
	}

	return p;
}
