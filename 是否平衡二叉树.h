#pragma once
#include<iostream>
#include"二叉树.h"
using namespace std;

/*核心思想：后序遍历，先判断左右子树是否为平衡二叉树，再判断根节点是否为平衡二叉树
* 参数：树中的一个节点
* 返回值：该节点为根的树为平衡树则返回该树的高度，不为平衡二叉树则返回-1
*/
int isBalancedCore(TreeNode* root)
{
	//鲁棒性操作以及递归终止条件
	if (root == NULL)	return 1;//如果该树为空树，则返回1（实际上只要不返回-1即可）
	if ((root->left == NULL) && (root->right == NULL))	return 1;//如果该节点为叶子结点，则返回1

	//得到左右子树的高度，并判断左右子树是否分别为平衡树
	int heightOfLeft, heightOfRight;//定义该节点左右子树的高度变量
	//左子树高度计算
	if (root->left == NULL)	heightOfLeft = 0;//如果左子树为空则左子树高度为0
	else
	{
		heightOfLeft = isBalancedCore(root->left);
		if (heightOfLeft == -1)	return -1;//如果左子树不平衡，则不再判断其他树，而是直接返回-1,一直向上返回直到离开该算法
	}
	//右子树高度计算，同左子树
	if (root->right == NULL)	heightOfRight = 0;
	else
	{
		heightOfRight = isBalancedCore(root->right);
		if (heightOfRight == -1)	return -1;
	}

	//利用左右子树高度判断该树是否平衡
	if ((heightOfLeft - heightOfRight > 1) || (heightOfLeft - heightOfRight < -1))	return -1;//如果左右子树高度相差超过1，则该树为不平衡，直接返回-1
	return (heightOfLeft > heightOfRight ? heightOfLeft : heightOfRight) + 1;//否则选左右子树中较大高度，再加一即为该树高度，向上返回
}

bool isBalanced(TreeNode* root)
{
	if (isBalancedCore(root) == -1)	return false;
	return true;
}