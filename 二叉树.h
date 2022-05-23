#pragma once
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
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
TreeNode* createTree(vector<int> numsOfTree)
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

/*��ӡ�����ݹ��������*/
void printTreeInRec(TreeNode* root)
{
	if (!root) return;
	printTreeInRec(root->left);
	cout << root->val << endl;
	printTreeInRec(root->right);
}

/*��ӡ���������������*/
void printTreeInIte(TreeNode* root)
{
	if (!root)    return;
	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode* temp = s.top();
		if (temp)
		{
			s.pop();
			if (temp->right)  s.push(temp->right);
			s.push(temp);
			s.push(NULL);
			if (temp->left)   s.push(temp->left);

		}
		else
		{
			s.pop();
			temp = s.top();
			s.pop();
			cout << temp->val << endl;
		}
	}
}


/*��ӡ�����ݹ�ǰ�����*/
void printTreePreRec(TreeNode* root)
{
	if (!root) return;
	cout << root->val << endl;
	printTreePreRec(root->left);
	printTreePreRec(root->right);
}

/*��ӡ��������ǰ�����*/
void printTreePreIte(TreeNode* root)
{
	if (!root)    return;
	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode* temp = s.top();
		if (temp)
		{
			s.pop();
			if (temp->right)  s.push(temp->right);
			if (temp->left)   s.push(temp->left);
			s.push(temp);
			s.push(NULL);
		}
		else
		{
			s.pop();
			temp = s.top();
			s.pop();
			cout << temp->val << endl;
		}
	}
}

/*��ӡ�����ݹ�������*/
void printTreePosRec(TreeNode* root)
{
	if (!root) return;
	printTreePosRec(root->left);
	printTreePosRec(root->right);
	cout << root->val << endl;
}

/*��ӡ���������������*/
void printTreePosIte(TreeNode* root)
{
	if (!root)    return;
	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode* temp = s.top();
		if (temp)
		{
			s.pop();
			s.push(temp);
			s.push(NULL);
			if (temp->right)  s.push(temp->right);
			if (temp->left)   s.push(temp->left);

		}
		else
		{
			s.pop();
			temp = s.top();
			s.pop();
			cout << temp->val << endl;
		}
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
