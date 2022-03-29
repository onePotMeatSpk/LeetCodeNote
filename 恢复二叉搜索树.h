#pragma once
#include"������.h"
//��Ŀ���ָ�����������
// ��Ŀ��������������������ĸ��ڵ� root �������е� ǡ�� �����ڵ��ֵ������ؽ��������ڲ��ı���ṹ������£��ָ��������

//����˼·�������������£������������������ڵ�ֵӦ��Ϊ������������ͼ���Է��֣������ǰ�ڵ�С��ǰ�ڵ㣬��˵��ǰ�ڵ��
//ǰ�ڵ�����һ���쳣����Ŀ��˵������������������ô����������У������ĵ�һ�����ں����ڵ�Ľڵ���ǵ�һ���쳣�ڵ㣬����
//�����һ��С��ǰ�ڵ�ĵ�ǰ�ڵ���ǵڶ����쳣�ڵ�

//������������������Ӷ��õ��쳣�ڵ�
void recoverTreeCore(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2, TreeNode*& pre) {
    if (!root)   return;
    //����������
    //ֱ�Ӱѵ�ǰ����pre��������������Ϊ����ͼ����⣬��ǰ��������˵������ǰ�ڵ���ǵ�ǰ����ǰ�ڵ�
    recoverTreeCore(root->left, mistake1, mistake2, pre);
    //���ǰ�ڵ�ΪNULL��˵����ǰ�ڵ��������������һ֦����Ȼ��ǰ�ڵ�
    //���ǰ�ڵ㲻ΪNULL��˵���Ѿ�����������˵ĵ�һ���ڵ�
    if (pre)
    {
        //��ǰ�ڵ�ֵС��ǰ�ڵ�ֵ���쳣��
        if (root->val < pre->val)
        {
            //�쳣�ڵ㶼��û��ȷ�������Ȱ���һ�����ϣ�mistake1�϶����쳣�ڵ��д���Ǹ�����Ϊ�������ĵ�һ���쳣�ڵ�
            if (!mistake1)
            {
                mistake1 = pre;
                mistake2 = root;
            }
            //������������˱�mistake2��С�Ľڵ㣬�Ǿ͸���mistake2��ֱ���������һ���쳣�ڵ�
            else if (root->val < mistake2->val)
                mistake2 = root;
        }
    }
    pre = root;
    //����������
    recoverTreeCore(root->right, mistake1, mistake2, pre);
}
void recoverTree(TreeNode* root) {
    TreeNode* mistake1 = NULL;
    TreeNode* mistake2 = NULL;
    TreeNode* pre = NULL;

    recoverTreeCore(root, mistake1, mistake2, pre);
    //�������ڵ��ֵ
    int temp = mistake1->val;
    mistake1->val = mistake2->val;
    mistake2->val = temp;
}