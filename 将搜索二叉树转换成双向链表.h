#pragma once
#include"������.h"

//��ʵ����������������
void help(TreeNode* root, TreeNode*& pre) {
    if (!root)
        return;

    help(root->left, pre);

    if (pre)
    {
        pre->right = root;
        root->left = pre;
    }
    pre = root;

    help(root->right, pre);
}

TreeNode* treeToDoublyList(TreeNode* root) {
    if (!root)
        return NULL;

    TreeNode* head = root;
    while (head->left)
        head = head->left;

    TreeNode* tail = root;
    while (tail->right)
        tail = tail->right;

    TreeNode* pre = NULL;
    help(root, pre);

    head->left = tail;
    tail->right = head;

    return head;
}