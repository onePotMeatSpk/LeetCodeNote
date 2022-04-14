#pragma once
#include<string>
#include<queue>
#include"������.h"

using namespace std;

//����:ÿ���ڵ�val��ת��Ϊ����string������string�У��սڵ�ת��Ϊ"#"���ǿսڵ�valʹ��to_string()����ת������ÿ���ڵ���
// һ��'!'��Ϊ��������Թ������л���ʱ��ʹ�á�

//****************************************************ǰ�����********************************************************//
//ǰ��������л�������
string serializePre(TreeNode* root) {
	if (!root)	return "#!";
	return to_string(root->val) + "!" + serializePre(root->left) + serializePre(root->right);
}

//ǰ����������л����������ĺ���
TreeNode* deserializePreCore(string& data, int& index) {
	if (index >= data.size())	return NULL;

	//�ýڵ����л����string
	string buffer;
	while (data[index] != '!')
	{
		buffer += data[index++];
	}
	index++;

	//�ýڵ�Ϊ��
	if (buffer == "#")
		return NULL;
	//�ýڵ㲻Ϊ��
	else
	{
		TreeNode* root = new TreeNode(atoi(buffer.c_str()));
		root->left = deserializePreCore(data, index);
		root->right = deserializePreCore(data, index);
		return root;
	}	
}

//ǰ����������л�������
TreeNode* deserializePre(string data) {
	int index = 0;
	return deserializePreCore(data, index);
}


//****************************************************�������********************************************************//
//����������л�������
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

//������������л�������
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