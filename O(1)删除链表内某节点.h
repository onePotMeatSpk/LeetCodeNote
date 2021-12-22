#pragma once
#include"��������.h"

//ʱ�临�Ӷ�O(1)
//˼�룺��ɾ���ڵ��next�ڵ��ֵ���ǵ�ɾ���ڵ㣬Ȼ��ɾ���ڵ��nextָ�����¸��ڵ㣬�����ͱ����˴�ͳ�ڵ�ɾ��˼���б�����
//		��ɾ���ڵ��pre��O(N)�ĸ��Ӷȡ�
//ȱ�㣺һ�����㷨������ǰ��֪Ҫɾ���ڵ��ָ�룬���Ǻܲ�����ģ���Ϊɾ���ڵ��һ��˼������֪��ֵ����������֪�ڵ�
//		��������ڶ���������Ľڵ㲢����head�б��еĽڵ㣬������һ���б��еĽڵ㣬����㷨�ᷢ������
void deleteOneNode(ListNode*& head, ListNode* deleteNode)
{
	//ͷΪ�ջ�Ҫɾ�ڵ�Ϊ��
	if (!head || !deleteNode)	return;
	//ɾ������ͷ��㣬��ͷ�������ƶ�
	if (head == deleteNode)
	{
		head = head->next;
		return;
	}
	//ɾ������β��㣬����ô�ͳ�ڵ�ɾ���㷨�����Ӷ�ΪO(N)�������Ⲣ���ᵼ�������㷨���Ӷ�������((N-1)*O(1)+O(N))/N=O(1)
	if (deleteNode->next == NULL)
	{
		ListNode* pPre = NULL;
		ListNode* pCur = head;
		while (pCur != deleteNode)
		{
			pPre = pCur;
			pCur = pCur->next;
		}
		pPre->next = pCur->next;
		return;
	}
	//�����㷨
	deleteNode->val = deleteNode->next->val;
	deleteNode->next = deleteNode->next->next;
}