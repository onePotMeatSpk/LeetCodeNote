#pragma once
#include<iostream>
#include<string>
#include"二叉树.h"

using namespace std;

//前序遍历序列化二叉树
string serializePre(TreeNode* root) {
	if (!root)	return "#!";
	return to_string(root->val) + "!" + serializePre(root->left) + serializePre(root->right);
}

//前序遍历反序列化二叉树核心函数
TreeNode* deserializePreCore(string& data, int& index) {
	if (index >= data.size())	return NULL;

	//该节点序列化后的string
	string buffer;
	while (data[index] != '!')
	{
		buffer += data[index++];
	}
	index++;

	//该节点为空
	if (buffer == "#")
		return NULL;
	//该节点不为空
	else
	{
		TreeNode* root = new TreeNode(atoi(buffer.c_str()));
		root->left = deserializePreCore(data, index);
		root->right = deserializePreCore(data, index);
		return root;
	}	
}

//前序遍历反序列化二叉树
TreeNode* deserializePre(string data) {
	int index = 0;
	return deserializePreCore(data, index);
}

