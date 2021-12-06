#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include"������.h"

using namespace std;


//�����ӡ
vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> nextLevel, thisLevel;
	vector<vector<int>> vv;
	vector<int> v;

	//³��
	if (!root)	return vv;

	//��ʼ��
	nextLevel.push(root);

	//����
	while (!nextLevel.empty())
	{
		//������Ԫ�ظ���
		v.clear();
		thisLevel = nextLevel;
		while (!nextLevel.empty())
			nextLevel.pop();

		while (!thisLevel.empty())
		{
			v.push_back(thisLevel.front()->val);
			if (thisLevel.front()->left)	nextLevel.push(thisLevel.front()->left);
			if (thisLevel.front()->right)	nextLevel.push(thisLevel.front()->right);
			thisLevel.pop();
		}

		vv.push_back(v);
	}

	return vv;
}


//Z���δ�ӡ
vector<vector<int>> levelOrderZ(TreeNode* root) {
	stack<TreeNode*> nextLevel, thisLevel;
	vector<vector<int>> vv;
	vector<int> v;
	bool flagOdd = false;//true��ʾ��ǰΪ�����У�����Ϊż����

	//³��
	if (!root)	return vv;

	//��ʼ��
	nextLevel.push(root);

	//����
	while (!nextLevel.empty())
	{
		//������ż
		flagOdd = !flagOdd;

		//������Ԫ�ظ���
		v.clear();
		thisLevel = nextLevel;
		while (!nextLevel.empty())
			nextLevel.pop();

		//����
		while (!thisLevel.empty())
		{
			v.push_back(thisLevel.top()->val);

			//��ǰΪ�����У�����һ��Ӧ�ô��������ӡ������Ӧ�ô���������ջ
			if (flagOdd)
			{
				if (thisLevel.top()->left)	nextLevel.push(thisLevel.top()->left);
				if (thisLevel.top()->right)	nextLevel.push(thisLevel.top()->right);
			}
			//��ǰΪż���У�����һ��Ӧ�ô������Ҵ�ӡ������Ӧ�ô���������ջ
			else
			{
				if (thisLevel.top()->right)	nextLevel.push(thisLevel.top()->right);
				if (thisLevel.top()->left)	nextLevel.push(thisLevel.top()->left);	
			}
			
			thisLevel.pop();
		}

		vv.push_back(v);
	}

	return vv;
}