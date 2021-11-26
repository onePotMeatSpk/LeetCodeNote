#pragma once
#include<iostream>
#include<string>
#include"二叉树.h"

using namespace std;

//表示在打印时，当前节点的父节点位于其什么方位
enum fatherLocation
{
	Up,		//上方
	Down,	//下方
	None	//无父节点
};

//此函数将二叉树的拓扑图逆时针旋转90度后打印
//算法思想：实质上是中序遍历（只不过顺序是右中左）
//root：当前遍历节点
//level：当前节点所在层数
//fl：当前节点的父节点在哪个方位
void printTreeDirectly(TreeNode* root, int level=1, fatherLocation fl=None)
{
	//鲁棒
	if (!root)	return;

	//遍历右子树
	printTreeDirectly(root->right, level + 1, Down);

	//打印当前遍历节点，每个节点都单独打印一行
	//当前节点位于二叉树第level层，则打印时为避免节点的层序关系不直观，打印每个节点val前，其左边应留有level-1片空白
	//每片空白由13个空格组成，其中10个表示int类型最多10位，1个表示可能出现的负号，2个代表/\、\/、||
	for (int i = 1; i < level; i++)
		cout << "             ";
	//打印节点本身
	//在val前加一符号以表示当前节点的父节点位于其什么方位，/\表示在其上方、\/表示在其下方、||表示无父节点
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

	//遍历左子树
	printTreeDirectly(root->left, level + 1, Up);
}