#pragma once
#include"������.h"
//����108
//��Ŀ������������ת��Ϊ����������
//��Ŀ����������һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� �߶�ƽ�� ������������


//˼·��ȡ�����е�Ϊ������Ϊ����������Ϊ������

//����1���ݹ�
TreeNode* dfsSortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r)   return NULL;

    int m = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left = dfsSortedArrayToBST(nums, l, m - 1);
    root->right = dfsSortedArrayToBST(nums, m + 1, r);

    return root;

}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfsSortedArrayToBST(nums, 0, nums.size() - 1);
}


//����2���������
TreeNode* sortedArrayToBST(vector<int>& nums) {
    queue<TreeNode*> q;
    queue<int> qL;
    queue<int> qR;

    TreeNode* root = new TreeNode(0);
    q.push(root);
    qL.push(0);
    qR.push(nums.size() - 1);

    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        int l = qL.front();
        int r = qR.front();
        qL.pop();
        qR.pop();

        int m = l + (r - l) / 2;
        temp->val = nums[m];

        if (l <= m - 1)
        {
            temp->left = new TreeNode(0);
            q.push(temp->left);
            qL.push(l);
            qR.push(m - 1);
        }

        if (r >= m + 1)
        {
            temp->right = new TreeNode(0);
            q.push(temp->right);
            qL.push(m + 1);
            qR.push(r);
        }
    }

    return root;
}