#pragma once
#include"������.h"
#include<queue>
using namespace std;

//����104
//��Ŀ����������������
//��Ŀ����������һ�����������ҳ��������ȡ�
			//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
			//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

//����1������ݹ�
int maxDepth(TreeNode* root) {
	if (root == NULL)	return 0;
	int heightOfLeft = maxDepth(root->left);
	int heightOfRight = maxDepth(root->right);
	return max(heightOfLeft, heightOfRight) + 1;
}

//����2���������
int maxDepth(TreeNode* root) {
	if (root == NULL)	return 0;
	
	queue<TreeNode*> q;
	q.push(root);

	int depth = 0;

	while (!q.empty())
	{
		depth++;
		int count = q.size();
		while (count--)
		{
			TreeNode* temp = q.front();
			q.pop();

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}
	}

	return depth;
}
