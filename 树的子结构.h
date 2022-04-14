#pragma once
#include"������.h"
using namespace std;

bool isTheSame(TreeNode* A, TreeNode* B);

//�������������ж�B�Ƿ�A֮�ӽṹ��Լ�����������������ӽṹ
bool isSubStructure(TreeNode* A, TreeNode* B) {
	//BΪ���������������ӽṹ
	if (!B)	return false;
	//AΪ�գ�˵���Ѿ�����A��Ҷ��Ҳû�ҵ�B
	if (!A)	return false;
	//AB��ͬ�����ж�AB�ӽṹ�Ƿ���ͬ
	if (A->val == B->val)
		if (isTheSame(A, B))
			return true;
	//AB��ͬ����AB�ӽṹ��ͬ�������µݹ���������
	return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

bool isTheSame(TreeNode* A, TreeNode* B) {
	//���B�գ�˵���Ѿ���B�������
	if (!B)	return true;
	//���B���յ���A�գ���A��������Bͬ
	if (!A)	return false;
	//�������ֵ��һ��
	if (A->val != B->val)	return false;
	//�������������������������һ��
	if ((!isTheSame(A->left, B->left)) || (!isTheSame(A->right, B->right)))	return false;
	//���϶�һ����˵��������ȫ��ͬ
	return true;
}