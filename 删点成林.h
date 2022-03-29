#pragma once
#include"二叉树.h"
//题目：删点成林
//题目描述：
// 
//解题思路：后序遍历+哈希set查找。
//1.采用后序遍历，而非其他遍历的原因是。其他遍历都会有先处理父亲的情况，如果这个父亲要被删除，就会使得原先的树不完整，从而
//使得递归无法继续进行。后序遍历保证最后处理父亲，就算删除了节点，也不会影响递归的后序进行。
//2.哈希set查找，作用在判断某节点是否在被删列表内。如果直接使用原本的vector进行查找，将会使得时间复杂度为O(MN)，N为节点数，
// M为要删除的节点数;而将vector中数据导入哈希set中，再利用哈希set进行查找，复杂度只有O(M)。

TreeNode* delNodesCore(TreeNode*& root, const unordered_set<int>& set, vector<TreeNode*>& vec) {
    if (!root)   return NULL;
    delNodesCore(root->left, set, vec);
    delNodesCore(root->right, set, vec);
    if (set.find(root->val) != set.end())
    {
        if (root->left)  vec.push_back(root->left);
        if (root->right)  vec.push_back(root->right);
        delete(root);
        root = NULL;
    }
    return root;
}


vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> vec;
    unordered_set<int> set(to_delete.begin(), to_delete.end());
    delNodesCore(root, set, vec);
    if (root)   vec.push_back(root);
    return vec;
}