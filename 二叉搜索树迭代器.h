#pragma once
#include<stack>
#include"������.h"
using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        nodeRoot = root;
    }

    int next() {
        //���������ǳ�ʼ״̬
        if (s.empty() && nodeRoot)
        {
            TreeNode* temp = nodeRoot;
            nodeRoot = NULL;
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
        }
        //�������ѷǳ�ʼ״̬
        //��ǰ�ڵ�û������������nextΪ�丸�ڵ�
        else if (s.top()->right == NULL)
            s.pop();
        //��ǰ�ڵ�������������nextΪ���������������ڵ�
        else
        {
            TreeNode* temp = s.top()->right;
            s.pop();
            s.push(temp);
            temp = temp->left;
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
        }

        return s.top()->val;
    }

    bool hasNext() {
        //����ǰ���������ǳ�ʼ״̬
        if (nodeRoot)    return true;
        //����ǰ�ڵ���������
        if (s.top()->right)  return true;
        //����ǰ�ڵ��и��ڵ�
        if (s.size() >= 2) return true;

        return false;

    }

private:
    stack<TreeNode*> s;
    TreeNode* nodeRoot;
};