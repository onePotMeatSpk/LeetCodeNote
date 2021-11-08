#pragma once
#include<iostream>
#include<vector>
using namespace std;

//单向链表结构体
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

//创建单向链表函数（输入一个vector）
//返回链表头节点指针
ListNode* createList(vector<int> v);

//打印单向链表函数（输入一个链表头）
void printList(ListNode* head);