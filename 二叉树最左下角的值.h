#pragma once
#include"������.h"
//��Ŀ�������������½ǵ�ֵ
//��Ŀ����������һ���������� ���ڵ� root�����ҳ��ö���������ײ������ߵĽڵ��ֵ�������������������һ���ڵ㡣


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