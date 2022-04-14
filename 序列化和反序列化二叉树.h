#pragma once
#include<string>
#include<queue>
#include"二叉树.h"

using namespace std;

//解释:每个节点val都转化为单个string并入总string中，空节点转化为"#"，非空节点val使用to_string()方法转化。在每个节点后加
// 一个'!'作为定界符，以供反序列化的时候使用。

//****************************************************前序遍历********************************************************//
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


//****************************************************层序遍历********************************************************//
//层序遍历序列化二叉树
string serializeLevel(TreeNode* root) {
	queue<TreeNode*> thisLevel, nextLevel;
	nextLevel.push(root);
	string s;

	while (!nextLevel.empty())
	{
		thisLevel = nextLevel;
		while (!nextLevel.empty())	nextLevel.pop();

		while (!thisLevel.empty())
		{
			if (!thisLevel.front())
				s += "#!";
			else
			{
				s += (to_string(thisLevel.front()->val) + "!");
				nextLevel.push(thisLevel.front()->left);
				nextLevel.push(thisLevel.front()->right);
			}
			thisLevel.pop();
		}
	}

	return s;
}

//层序遍历反序列化二叉树
TreeNode* deserializeLevel(string data) {
	int index = 0;
	string buffer;
	queue<TreeNode*> thisLevel, nextLevel;
	TreeNode* root = NULL;

	while (data[index] != '!')
		buffer += data[index++];
	index++;

	if (buffer == "#")
		return NULL;
	else
	{
		root = new TreeNode(atoi(buffer.c_str()));
		nextLevel.push(root);
	}
	buffer.clear();

	while (!nextLevel.empty())
	{
		thisLevel = nextLevel;
		while (!nextLevel.empty())	nextLevel.pop();

		while (!thisLevel.empty())
		{
			if (index >= data.size())	return root;
			while (data[index] != '!')	buffer += data[index++];
			index++;
			if (buffer != "#")
			{
				thisLevel.front()->left = new TreeNode(atoi(buffer.c_str()));
				nextLevel.push(thisLevel.front()->left);
			}	
			buffer.clear();

			if (index >= data.size())	return root;
			while (data[index] != '!')	buffer += data[index++];
			index++;
			if (buffer != "#")
			{
				thisLevel.front()->right = new TreeNode(atoi(buffer.c_str()));
				nextLevel.push(thisLevel.front()->right);
			}
			buffer.clear();

			thisLevel.pop();
		}
	}

	return root;
}