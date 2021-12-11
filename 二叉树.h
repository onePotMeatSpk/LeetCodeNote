#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

/*打印树：递归中序遍历*/
void printTreeInRecursion(TreeNode* root)
{
	if (!root) return;
	printTreeInRecursion(root->left);
	cout << root->val << endl;
	printTreeInRecursion(root->right);
}

/*打印树：迭代中序遍历*/
void printTreeInIteration(TreeNode* root)
{
	if (!root)	return;

	stack<TreeNode*> s;
	s.push(root);
	TreeNode* cur = root->left;
	while (s.size() || cur)
	{
		if(cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		else
		{
			cout << s.top()->val << endl;
			cur = s.top()->right;
			s.pop();
		}
	}
}


/*打印树：递归前序遍历*/
void printTreePreRecursion(TreeNode* root)
{
	if (!root) return;
	cout << root->val << endl;
	printTreePreRecursion(root->left);
	printTreePreRecursion(root->right);
}

/*打印树：迭代前序遍历*/
void printTreePreIteration(TreeNode* root)
{
	if (!root)	return;
	TreeNode* temp = NULL;
	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		cout << s.top()->val << endl;
		temp = s.top();
		s.pop();
		if (temp->right)	s.push(temp->right);
		if (temp->left)	s.push(temp->left);
	}
}

/*打印树：递归后序遍历*/
void printTreePosRecursion(TreeNode* root)
{
	if (!root) return;
	printTreePosRecursion(root->left);
	printTreePosRecursion(root->right);
	cout << root->val << endl;
}

/*打印树：迭代后序遍历*/
void printTreePosIteration(TreeNode* root)
{
	if (!root)	return;
	stack<TreeNode*>s;
	stack<TreeNode*>sPutOut;
	TreeNode* temp = NULL;
	s.push(root);

	while (!s.empty())
	{
		temp = s.top();
		s.pop();
		sPutOut.push(temp);

		if (temp->left)	s.push(temp->left);
		if (temp->right)	s.push(temp->right);
	}

	while (!sPutOut.empty())
	{
		cout << sPutOut.top()->val << endl;
		sPutOut.pop();
	}
}







/*删除树*/
void deleteTree(TreeNode* root)
{
	if (root == NULL)	return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
