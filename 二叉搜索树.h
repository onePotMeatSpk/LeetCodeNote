#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(NULL), right(NULL) {};
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

/*����������������һ����*/
TreeNode* createTree(TreeNode* root)
{
	if (root == NULL)	return NULL;
	TreeNode* rootCopy = new TreeNode(root->val);
	rootCopy->left = createTree(root->left);
	rootCopy->right = createTree(root->right);
	return rootCopy;
}

/*��������������leetcode��������ʾԭ�򣬲������*/
TreeNode* createTree(vector<int>& numsOfTree)
{
	if (numsOfTree.empty())	return NULL;
	queue<TreeNode*> queueOfThisLevel, queueOfNextLevel;
	TreeNode* head = new TreeNode(numsOfTree[0]);
	queueOfNextLevel.push(head);
	int indexAlreadyTraversed = 1;
	while (queueOfNextLevel.size())
	{
		queueOfThisLevel = queueOfNextLevel;
		while (queueOfNextLevel.size())
			queueOfNextLevel.pop();
		int numberOfNodesThisLevel = queueOfThisLevel.size();
	}
}

/*ɾ����*/
void deleteTree(TreeNode* root)
{
	if (root == NULL)	return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
