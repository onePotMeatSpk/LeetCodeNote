#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

/*创建新树，拷贝另一个树*/
TreeNode* createTree(TreeNode* root);
/*创建新树，根据leetcode二叉树表示原则，层序遍历*/
TreeNode* createTree(vector<int>& numsOfTree);
/*删除树*/
void deleteTree(TreeNode* root);

