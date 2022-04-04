#pragma once
#include"������.h"

//��Ŀ������֮�� IV - ���� BST
//��Ŀ����������һ������������ root ��һ��Ŀ���� k����� BST �д�������Ԫ�������ǵĺ͵��ڸ�����Ŀ�������򷵻� true��

TreeNode* isExist(TreeNode* root, int k)
{
    while (root)
    {
        if (k == root->val)  return root;
        if (k < root->val)
        {
            root = root->left;
            continue;
        }
        if (k > root->val)
        {
            root = root->right;
            continue;
        }
    }
    return NULL;
}
bool findTargetCore(TreeNode* root, int& k, TreeNode*& head) {
    if (!root)   return 0;
    if (findTargetCore(root->left, k, head))   return 1;
    TreeNode* t = isExist(head, k - root->val);
    if (t && t != root)    return 1;//һ��Ҫ���鵽���Ƿ�Ϊ��������Ǳ���Ļ�һ�����ܷ���1
    if (findTargetCore(root->right, k, head))   return 1;
    return 0;
}
bool findTarget(TreeNode* root, int k) {
    TreeNode* head = root;
    return findTargetCore(root, k, head);
}