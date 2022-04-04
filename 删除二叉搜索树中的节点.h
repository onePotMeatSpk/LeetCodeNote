#pragma once
#include"������.h"

//����һ���ݹ飩��ֻ����ָ���ϵ�����޸Ľڵ�ֵ
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

//������������һ�ĵ����汾����ֻ����ָ���ϵ�����޸Ľڵ�ֵ
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

	//���Ҫɾ�����Ǹ�
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

	//���Ҫɾ���Ĳ��Ǹ�
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




////��δ��ɣ��������������޸Ľڵ�ֵ��������ָ���ϵ
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
//	//���ɾ�����Ǹ�
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
//	//���ɾ�Ĳ��Ǹ�
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
