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