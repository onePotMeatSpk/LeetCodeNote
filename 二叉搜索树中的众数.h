#pragma once
#include"������.h"
#include<stack>
#include<unordered_map>
using namespace std;

//����501
//��Ŀ�������������е�����
//��Ŀ����������һ�����ظ�ֵ�Ķ�����������BST���ĸ��ڵ� root ���ҳ������� BST �е����� ��������������Ƶ����ߵ�Ԫ�أ���
			//��������в�ֹһ�����������԰� ����˳�� ���ء�
			//
			//�ٶ� BST �������¶��壺
			//
			//����������������ڵ��ֵ С�ڵ��� ��ǰ�ڵ��ֵ
			//����������������ڵ��ֵ ���ڵ��� ��ǰ�ڵ��ֵ
			//�����������������Ƕ���������


////������������BST����Ҫ���������ȱ���һ��ͳ�����ֳ��ִ������ٶԴ�����������ҳ�����
//map���ڵ�ֵ�ͳ��ִ����Ķ�Ӧ��
//v����Ŀ��Ҫ
//void dfsFindMode(TreeNode* root, unordered_map<int, int>& map, vector<int>& v) {
//    if (!root)   return;
//    dfsFindMode(root->left, map, v);
//
//    map[root->val]++;
//    if (v.empty())   v.push_back(root->val);
//    else if (root->val != v.back())  v.push_back(root->val);
//
//    dfsFindMode(root->right, map, v);
//}
//vector<int> findMode(TreeNode* root) {
//    if (!root)   return vector<int>();
//    unordered_map<int, int> map;
//    vector<int> v;
//    dfsFindMode(root, map, v);
//
//    stack<int> s;
//    s.push(v[0]);
//    for (int i = 1; i < v.size(); i++)
//        if (map[v[i]] >= map[s.top()])   s.push(v[i]);
//
//    int maxFre = map[s.top()];
//    vector<int> ret;
//    while (!s.empty())
//    {
//        if (map[s.top()] == maxFre)
//        {
//            ret.push_back(s.top());
//            s.pop();
//        }
//        else    break;
//    }
//
//    return ret;
//}


//����������BST����ֻһ�α�������
//�˴�Ϊ����ݹ�ʵ�ַ�����Ҳ�ɸ�������
//maxFre�������ִ���
//fre�����ڽڵ���ִ���
//pre��ǰ�ڵ�
//v����Ŀ��Ҫ
void dfsFindMode(TreeNode* root, int& maxFre, int& fre, TreeNode*& pre, vector<int>& v) {
	if (!root)	return;

	dfsFindMode(root->left, maxFre, fre, pre, v);

	if (!pre)
	{
		fre = 1;
		maxFre = 1;
		v.push_back(root->val);
	}
	else
	{
		
		if (root->val != pre->val)//���ڽڵ���ǰ�ڵ㲻ͬ
			fre = 1;
		else//��ͬ
			fre++;

		if (fre == maxFre)//���ڽڵ�ĳ��ִ����������ִ������
			v.push_back(root->val);//�����ڽڵ����
		else if (fre > maxFre)//���ڽڵ�ĳ��ִ��������������ִ���
		{
			maxFre = fre;//���������ִ���
			v.clear();//��v��գ���Ϊ֮ǰ�Ľڵ���ִ�����С�����ڽڵ���
			v.push_back(root->val);//�������ڽڵ����
		}
	}
	pre = root;//����ǰ�ڵ�

	dfsFindMode(root->right, maxFre, fre, pre, v);
}
vector<int> findMode(TreeNode* root) {
	int maxFre = 0;
	int fre = 0;
	TreeNode* pre = NULL;
	vector<int> v;
	dfsFindMode(root, maxFre, fre, pre, v);
	return v;
}





