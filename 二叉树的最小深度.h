#pragma once
#include"������.h"
#include<queue>
using namespace std;
//����111
//��Ŀ������������С���
//��Ŀ����������һ�����������ҳ�����С��ȡ�
			//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
			//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

//����1������ݹ�
int minDepth(TreeNode* root) {
	if (!root)	return 0;//³��

	if (!root->left && !root->right)	return 1;//����ǵݹ���ֹ����

	int depth = INT_MAX;
	if (root->left)	depth = min(depth, minDepth(root->left));
	if (root->right)	depth = min(depth, minDepth(root->right));

	return depth + 1;
}

//����2���������
int minDepth(TreeNode* root) {
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
			
			if (!temp->left && !temp->right)	return depth;//������һ��Ҷ�ӽ�㣬�ͷ��ص�ǰ���

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}
	}

	return depth;
}
