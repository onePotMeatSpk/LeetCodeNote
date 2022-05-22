#pragma once
#include<queue>
#include<vector>
#include"������.h"
using namespace std;
//����199
//��Ŀ��������������ͼ
//��Ŀ����������һ���������� ���ڵ� root�������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��

//����ͨ��������Ļ����ϣ���ÿ��Ķ��е����һ��Ԫ�أ�Ҳ����countΪ0ʱ��������vector��
vector<int> rightSideView(TreeNode* root) {
	vector<int> vRet;
	if (!root)	return vRet;
	queue<TreeNode*> q;

	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		while (count--)
		{
			TreeNode* temp = q.front();
			q.pop();
			if (!count)
				vRet.push_back(temp->val);

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}
	}

	return vRet;
}