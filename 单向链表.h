#pragma once
#include<iostream>
#include<vector>
using namespace std;

//��������ṹ��
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

//��������������������һ��vector��
//��������ͷ�ڵ�ָ��
ListNode* createList(vector<int> v);

//��ӡ����������������һ������ͷ��
void printList(ListNode* head);