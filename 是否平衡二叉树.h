#pragma once
#include<iostream>
#include"������.h"
using namespace std;

/*����˼�룺������������ж����������Ƿ�Ϊƽ������������жϸ��ڵ��Ƿ�Ϊƽ�������
* ���������е�һ���ڵ�
* ����ֵ���ýڵ�Ϊ������Ϊƽ�����򷵻ظ����ĸ߶ȣ���Ϊƽ��������򷵻�-1
*/
int isBalancedCore(TreeNode* root)
{
	//³���Բ����Լ��ݹ���ֹ����
	if (root == NULL)	return 1;//�������Ϊ�������򷵻�1��ʵ����ֻҪ������-1���ɣ�
	if ((root->left == NULL) && (root->right == NULL))	return 1;//����ýڵ�ΪҶ�ӽ�㣬�򷵻�1

	//�õ����������ĸ߶ȣ����ж����������Ƿ�ֱ�Ϊƽ����
	int heightOfLeft, heightOfRight;//����ýڵ����������ĸ߶ȱ���
	//�������߶ȼ���
	if (root->left == NULL)	heightOfLeft = 0;//���������Ϊ�����������߶�Ϊ0
	else
	{
		heightOfLeft = isBalancedCore(root->left);
		if (heightOfLeft == -1)	return -1;//�����������ƽ�⣬�����ж�������������ֱ�ӷ���-1,һֱ���Ϸ���ֱ���뿪���㷨
	}
	//�������߶ȼ��㣬ͬ������
	if (root->right == NULL)	heightOfRight = 0;
	else
	{
		heightOfRight = isBalancedCore(root->right);
		if (heightOfRight == -1)	return -1;
	}

	//�������������߶��жϸ����Ƿ�ƽ��
	if ((heightOfLeft - heightOfRight > 1) || (heightOfLeft - heightOfRight < -1))	return -1;//������������߶�����1�������Ϊ��ƽ�⣬ֱ�ӷ���-1
	return (heightOfLeft > heightOfRight ? heightOfLeft : heightOfRight) + 1;//����ѡ���������нϴ�߶ȣ��ټ�һ��Ϊ�����߶ȣ����Ϸ���
}

bool isBalanced(TreeNode* root)
{
	if (isBalancedCore(root) == -1)	return false;
	return true;
}