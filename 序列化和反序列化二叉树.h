#pragma once
#include<iostream>
#include<string>
#include"������.h"

using namespace std;

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

