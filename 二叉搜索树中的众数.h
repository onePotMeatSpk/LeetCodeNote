#pragma once
#include"二叉树.h"
#include<stack>
#include<unordered_map>
using namespace std;

//力扣501
//题目：二叉搜索树中的众数
//题目描述：给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
			//如果树中有不止一个众数，可以按 任意顺序 返回。
			//
			//假定 BST 满足如下定义：
			//
			//结点左子树中所含节点的值 小于等于 当前节点的值
			//结点右子树中所含节点的值 大于等于 当前节点的值
			//左子树和右子树都是二叉搜索树


////！！！！！非BST，就要笨方法：先遍历一遍统计数字出现次数，再对次数排序，最后找出众数
//map：节点值和出现次数的对应表
//v：题目所要
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


//！！！！是BST，则只一次遍历即可
//此处为中序递归实现方法，也可改做迭代
//maxFre：最大出现次数
//fre：现在节点出现次数
//pre：前节点
//v：题目所要
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
		
		if (root->val != pre->val)//现在节点与前节点不同
			fre = 1;
		else//相同
			fre++;

		if (fre == maxFre)//现在节点的出现次数和最大出现次数相等
			v.push_back(root->val);//将现在节点放入
		else if (fre > maxFre)//现在节点的出现次数超过了最大出现次数
		{
			maxFre = fre;//更新最大出现次数
			v.clear();//将v清空，因为之前的节点出现次数都小于现在节点了
			v.push_back(root->val);//并将现在节点放入
		}
	}
	pre = root;//更新前节点

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





