#pragma once
#include"二叉树.h"

//方法一（递归），只更改指向关系，不修改节点值
TreeNode* deleteNodeBST1(TreeNode* root, int key) {
	if (!root)	return NULL;

	if (key < root->val)
	{
		root->left = deleteNodeBST1(root->left, key);
		return root;
	}
	if (key > root->val)
	{
		root->right = deleteNodeBST1(root->right, key);
		return root;
	}

	if (!root->left && !root->right)
	{
		delete(root);
		return NULL;
	}

	if (root->left && root->right)
	{
		TreeNode* RL = root->right;
		while (RL->left)
			RL = RL->left;
		RL->left = root->left->right;
		root->left->right = root->right;
		TreeNode* temp = root->left;
		delete(root);
		return temp;
	}

	if (root->left)
	{
		TreeNode* temp = root->left;
		delete(root);
		return temp;
	}
	
	if (root->right)
	{
		TreeNode* temp = root->right;
		delete(root);
		return temp;
	}

}

//方法二（方法一的迭代版本），只更改指向关系，不修改节点值
TreeNode* deleteNodeBST2(TreeNode* root, int key) {
	TreeNode* head = root;
	TreeNode* prev = NULL;
	bool flagLR = 0;
	while (root)
	{
		if (root->val == key)	break;
		if (key < root->val)
		{
			flagLR = 0;
			prev = root;
			root = root->left;
			continue;
		}
		if (key > root->val)
		{
			flagLR = 1;
			prev = root;
			root = root->right;
			continue;
		}
	}
	if (!root)	return head;

	//如果要删除的是根
	if (root == head)
	{
		if (!root->left && !root->right)
		{
			delete(root);
			return NULL;
		}

		if (root->left && root->right)
		{
			TreeNode* L = root->left;
			TreeNode* RL = root->right;
			while (RL->left)	RL = RL->left;
			RL->left = root->left->right;
			root->left->right = root->right;
			delete(root);
			return L;
		}

		if (root->left)
		{
			TreeNode* temp = root->left;
			delete(root);
			return temp;
		}

		if (root->right)
		{
			TreeNode* temp = root->right;
			delete(root);
			return temp;
		}
	}

	//如果要删除的不是根
	if (!root->left && !root->right)
	{
		if (!flagLR)
			prev->left = NULL;
		else
			prev->right = NULL;
		delete(root);
		return head;
	}

	if (root->left && root->right)
	{
		TreeNode* L = root->left;
		TreeNode* RL = root->right;
		while (RL->left)	RL = RL->left;
		RL->left = root->left->right;
		root->left->right = root->right;
		if (!flagLR)
			prev->left = root->left;
		else
			prev->right = root->left;
		delete(root);
		return head;
	}

	if (root->left)
	{
		if (!flagLR)
			prev->left = root->left;
		else
			prev->right = root->left;
		delete(root);
		return head;
	}

	if (root->right)
	{
		if (!flagLR)
			prev->left = root->right;
		else
			prev->right = root->right;
		delete(root);
		return head;
	}
}




////（未完成）方法三，尽量修改节点值，而不是指向关系
//TreeNode* deleteNodeBST3(TreeNode* root, int key) {
//	TreeNode* head = root;
//	while (root)
//	{
//		if (key == root->val)	break;
//		if (key < root->val)
//		{
//			root = root->left;
//			continue;
//		}
//		if (key > root->val)
//		{
//			root = root->right;
//			continue;
//		}
//	}
//	if (!root)	return head;
//
//	//如果删除的是根
//	if (root == head)
//	{
//		if (!root->left && !root->right)
//		{
//			delete(root);
//			return NULL;
//		}
//
//		if (root->left && root->right)
//		{
//			TreeNode* LR = root->left->right;
//			if (LR)
//			{
//				TreeNode* prev = root->left;
//				while (LR->right)
//				{
//					prev = LR;
//					LR = LR->right;
//				}
//				root->val = LR->val;
//				delete(LR);
//				prev->right = NULL;
//				return root;
//			}
//			else
//			{
//				root->left->right = root->right;
//				TreeNode* temp = root->left;
//				delete(root);
//				return temp;
//			}
//		}
//
//		if (root->left)
//		{
//			TreeNode* temp = root->left;
//			delete(root);
//			return temp;
//		}
//
//		if (root->right)
//		{
//			TreeNode* temp = root->right;
//			delete(root);
//			return temp;
//		}
//	}
//
//	//如果删的不是根
//	if (!root->left && !root->right)
//	{
//		delete(root);
//		return NULL;
//	}
//
//	if (root->left && root->right)
//	{
//		TreeNode* LR = root->left->right;
//		if (LR)
//		{
//			TreeNode* prev = root->left;
//			while (LR->right)
//			{
//				prev = LR;
//				LR = LR->right;
//			}
//			root->val = LR->val;
//			delete(LR);
//			prev->right = NULL;
//			return root;
//		}
//		else
//		{
//			root->left->right = root->right;
//			TreeNode* temp = root->left;
//			delete(root);
//			return temp;
//		}
//	}
//
//	if (root->left)
//	{
//		TreeNode* temp = root->left;
//		delete(root);
//		return temp;
//	}
//
//	if (root->right)
//	{
//		TreeNode* temp = root->right;
//		delete(root);
//		return temp;
//	}
//
//}
