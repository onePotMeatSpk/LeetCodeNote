#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(NULL), right(NULL) {};
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

/*创建新树，拷贝另一个树*/
TreeNode* createTree(TreeNode* root)
{
	if (root == NULL)	return NULL;
	TreeNode* rootCopy = new TreeNode(root->val);
	rootCopy->left = createTree(root->left);
	rootCopy->right = createTree(root->right);
	return rootCopy;
}

/*创建新树，根据leetcode二叉树表示原则，层序遍历*/
TreeNode* createTree(vector<int>& numsOfTree)
{
	if (numsOfTree.empty())	return NULL;
	queue<TreeNode*> queueOfThisLevel, queueOfNextLevel;
	TreeNode* head = new TreeNode(numsOfTree[0]);
	queueOfNextLevel.push(head);
	int index = 1;
	TreeNode* newNode = NULL;
	while (queueOfNextLevel.size())
	{
		queueOfThisLevel = queueOfNextLevel;
		while (queueOfNextLevel.size())
			queueOfNextLevel.pop();
		while (queueOfThisLevel.size())
		{
			if (index < numsOfTree.size())
			{
				if (numsOfTree[index] != NULL)
				{
					newNode = new TreeNode(numsOfTree[index++]);
					queueOfThisLevel.front()->left = newNode;
					queueOfNextLevel.push(newNode);
				}
				else
					index++;
				
			}
			else
			{
				return head;
			}

			if (index < numsOfTree.size())
			{
				if (numsOfTree[index] != NULL)
				{
					newNode = new TreeNode(numsOfTree[index++]);
					queueOfThisLevel.front()->right = newNode;
					queueOfNextLevel.push(newNode);
				}
				else
					index++;
			}
			else
			{
				return head;
			}

			queueOfThisLevel.pop();
		}
	}

	return head;
}

/*打印树：中序遍历*/
void printTreePre(TreeNode* root)
{
	if (!root) return;
	printTreePre(root->left);
	cout << root->val << endl;
	printTreePre(root->right);
}

/*删除树*/
void deleteTree(TreeNode* root)
{
	if (root == NULL)	return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
