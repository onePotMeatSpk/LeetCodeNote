#pragma once
#include"二叉树.h"
using namespace std;

bool isTheSame(TreeNode* A, TreeNode* B);

//输入两个树，判断B是否A之子结构，约定空树非任意树的子结构
bool isSubStructure(TreeNode* A, TreeNode* B) {
	//B为空树，非任意树子结构
	if (!B)	return false;
	//A为空，说明已经到达A树叶子也没找到B
	if (!A)	return false;
	//AB相同，则判断AB子结构是否相同
	if (A->val == B->val)
		if (isTheSame(A, B))
			return true;
	//AB不同或者AB子结构不同，均向下递归左右子树
	return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

bool isTheSame(TreeNode* A, TreeNode* B) {
	//如果B空，说明已经将B遍历完毕
	if (!B)	return true;
	//如果B不空但是A空，则A不可能与B同
	if (!A)	return false;
	//如果两者值不一样
	if (A->val != B->val)	return false;
	//如果两者左子树或者右子树不一样
	if ((!isTheSame(A->left, B->left)) || (!isTheSame(A->right, B->right)))	return false;
	//以上都一样则说明两者完全相同
	return true;
}