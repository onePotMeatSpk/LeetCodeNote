#pragma once
#include"������.h"
//��Ŀ��ɾ�����
//��Ŀ������
// 
//����˼·���������+��ϣset���ҡ�
//1.���ú����������������������ԭ���ǡ����������������ȴ����׵����������������Ҫ��ɾ�����ͻ�ʹ��ԭ�ȵ������������Ӷ�
//ʹ�õݹ��޷��������С����������֤������ף�����ɾ���˽ڵ㣬Ҳ����Ӱ��ݹ�ĺ�����С�
//2.��ϣset���ң��������ж�ĳ�ڵ��Ƿ��ڱ�ɾ�б��ڡ����ֱ��ʹ��ԭ����vector���в��ң�����ʹ��ʱ�临�Ӷ�ΪO(MN)��NΪ�ڵ�����
// MΪҪɾ���Ľڵ���;����vector�����ݵ����ϣset�У������ù�ϣset���в��ң����Ӷ�ֻ��O(M)��

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