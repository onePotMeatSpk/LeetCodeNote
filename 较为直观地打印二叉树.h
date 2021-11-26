#pragma once
#include<iostream>
#include<string>
#include"������.h"

using namespace std;

//��ʾ�ڴ�ӡʱ����ǰ�ڵ�ĸ��ڵ�λ����ʲô��λ
enum fatherLocation
{
	Up,		//�Ϸ�
	Down,	//�·�
	None	//�޸��ڵ�
};

//�˺�����������������ͼ��ʱ����ת90�Ⱥ��ӡ
//�㷨˼�룺ʵ���������������ֻ����˳����������
//root����ǰ�����ڵ�
//level����ǰ�ڵ����ڲ���
//fl����ǰ�ڵ�ĸ��ڵ����ĸ���λ
void printTreeDirectly(TreeNode* root, int level=1, fatherLocation fl=None)
{
	//³��
	if (!root)	return;

	//����������
	printTreeDirectly(root->right, level + 1, Down);

	//��ӡ��ǰ�����ڵ㣬ÿ���ڵ㶼������ӡһ��
	//��ǰ�ڵ�λ�ڶ�������level�㣬���ӡʱΪ����ڵ�Ĳ����ϵ��ֱ�ۣ���ӡÿ���ڵ�valǰ�������Ӧ����level-1Ƭ�հ�
	//ÿƬ�հ���13���ո���ɣ�����10����ʾint�������10λ��1����ʾ���ܳ��ֵĸ��ţ�2������/\��\/��||
	for (int i = 1; i < level; i++)
		cout << "             ";
	//��ӡ�ڵ㱾��
	//��valǰ��һ�����Ա�ʾ��ǰ�ڵ�ĸ��ڵ�λ����ʲô��λ��/\��ʾ�����Ϸ���\/��ʾ�����·���||��ʾ�޸��ڵ�
	switch (fl)
	{
	case Up:
		cout << "/\\";
		cout << root->val << endl;
		break;
	case Down:
		cout << "\\/";
		cout << root->val << endl;
		break;
	case None:
		cout << "||";
		cout << root->val << endl;
		break;
	default:
		break;
	}

	//����������
	printTreeDirectly(root->left, level + 1, Up);
}