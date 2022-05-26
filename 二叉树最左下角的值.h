#pragma once
#include"������.h"
//����513
//��Ŀ���������½ǵ�ֵ
//��Ŀ����������һ���������� ���ڵ� root�����ҳ��ö���������ײ������ߵĽڵ��ֵ�������������������һ���ڵ㡣


//����1������ݹ飨����Ҳ���ԣ�����д�����ˣ�
//�����������������������
//maxDepth��¼��ǰ������������ڵ�����
//valTemp��¼maxDepth��Ӧ�ڵ��ֵ
//root��ʾ��һ��Ҫ��������
//depth��ʾ����һ������
void findBottomLeftValueCore(int& maxDepth, int& valTemp, TreeNode*& root, int depth)
{
    if (!root)   return;

    //�ҵ�һ��Ҷ�ӽ��
    if (!root->left && !root->right)
        if (maxDepth < depth)//��maxDepth����Ļ����͸���������Ⱥ�ֵ�����򲻸��£���Ⱥ�maxDepthһ��Ҳ�����£���Ϊ����
                             //������У���ߵĽڵ�϶����类��������
        {
            maxDepth = depth;
            valTemp = root->val;
        }

    findBottomLeftValueCore(maxDepth, valTemp, root->left, depth + 1);
    findBottomLeftValueCore(maxDepth, valTemp, root->right, depth + 1);
}

int findBottomLeftValue(TreeNode* root)
{
    int maxDepth = -1;
    int valTemp = 0;
    findBottomLeftValueCore(maxDepth, valTemp, root, 0);
    return valTemp;
}

//����2���������
int findBottomLeftValue(TreeNode* root) {
    if (!root)   return 0;

    queue<TreeNode*> q;
    q.push(root);

    TreeNode* ret = NULL;

    while (!q.empty())
    {
        int count = q.size();
        ret = q.front();
        while (count--)
        {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return ret->val;
}