#pragma once
#include"二叉树.h"
//力扣450
//题目：删除二叉搜索树中的节点
//题目描述：给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

//思路：BST二分自不必说。需要注意的是，如果被删除节点的左右子树均存在，注意删除节点后，BST的左小右大性质不被违背
//		实现方法：右子树放到左子树的最右下角，再将左子树顶上（或将左子树放到右子树的最左下角，再将右子树顶上）

//方法1:递归
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)   return NULL;

    //找到删除节点
    if (key == root->val) {
        //无左无右：直接置NULL
        if (!root->left && !root->right) root = NULL;
        //有一个子树：那个子树直接顶上
        else if (!root->left || !root->right)    root = root->left ? root->left : root->right;
        //有左右子树：右子树放到左子树的最右下角，再将左子树顶上
        else {
            TreeNode* cur = root->left;
            while (cur->right)   cur = cur->right;
            cur->right = root->right;
            root = root->left;
        }
    }
    //未找到删除节点
    else if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val)    root->right = deleteNode(root->right, key);

    return root;
}


//方法2：迭代
//注意：设置pre，保存前节点，以保证cur更改之后，可以链接到pre
//      还要设置flagLR，标志cur是前节点的左还是右
TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    bool flagLR = 0;
    while (cur)
    {
        //找到删除节点
        if (key == cur->val) {
            //无左无右：直接置NULL
            if (!cur->left && !cur->right) cur = NULL;
            //有一个子树：那个子树直接顶上
            else if (!cur->left || !cur->right)    cur = cur->left ? cur->left : cur->right;
            //有左右子树：右子树放到左子树的最右下角，再将左子树顶上
            else {
                TreeNode* curL = cur->left;
                while (curL->right)   curL = curL->right;
                curL->right = cur->right;
                cur = cur->left;
            }

            if (!pre)    return cur;
            if (flagLR)  pre->right = cur;
            else  pre->left = cur;
            break;
        }
        //未找到删除节点
        else if (key < cur->val) {
            flagLR = 0;
            pre = cur;
            cur = cur->left;
        }
        else if (key > cur->val) {
            flagLR = 1;
            pre = cur;
            cur = cur->right;
        }
    }

    return root;
}




