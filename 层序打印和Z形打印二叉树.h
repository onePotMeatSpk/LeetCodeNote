#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include"二叉树.h"

using namespace std;


//层序打印
vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> nextLevel, thisLevel;
	vector<vector<int>> vv;
	vector<int> v;

	//鲁棒
	if (!root)	return vv;

	//初始化
	nextLevel.push(root);

	//遍历
	while (!nextLevel.empty())
	{
		//新老行元素更新
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


//Z子形打印
vector<vector<int>> levelOrderZ(TreeNode* root) {
	stack<TreeNode*> nextLevel, thisLevel;
	vector<vector<int>> vv;
	vector<int> v;
	bool flagOdd = false;//true表示当前为奇数行，否则为偶数行

	//鲁棒
	if (!root)	return vv;

	//初始化
	nextLevel.push(root);

	//遍历
	while (!nextLevel.empty())
	{
		//更新奇偶
		flagOdd = !flagOdd;

		//新老行元素更新
		v.clear();
		thisLevel = nextLevel;
		while (!nextLevel.empty())
			nextLevel.pop();

		//遍历
		while (!thisLevel.empty())
		{
			v.push_back(thisLevel.top()->val);

			//当前为奇数行，则下一行应该从右往左打印，所以应该从左往右入栈
			if (flagOdd)
			{
				if (thisLevel.top()->left)	nextLevel.push(thisLevel.top()->left);
				if (thisLevel.top()->right)	nextLevel.push(thisLevel.top()->right);
			}
			//当前为偶数行，则下一行应该从左往右打印，所以应该从右往左入栈
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