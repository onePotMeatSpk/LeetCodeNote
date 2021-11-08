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

/*����������������һ����*/
TreeNode* createTree(TreeNode* root);
/*��������������leetcode��������ʾԭ�򣬲������*/
TreeNode* createTree(vector<int>& numsOfTree);
/*ɾ����*/
void deleteTree(TreeNode* root);

