#pragma once
#include<vector>
#include<queue>
using namespace std;
//力扣429
//题目：N叉树的层序遍历
//题目描述：给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。


//层序遍历，没啥讲的

//N叉树结构
struct Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//主函数
vector<vector<int>> levelOrder(Node* root) {
	vector<vector<int>> vAll;
	if (!root)	return vAll;
	vector<int> v;
	queue<Node*> q;

	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		while (count--)
		{
			Node* temp = q.front();
			q.pop();
			v.push_back(temp->val);
			for (int i = 0; i < temp->children.size(); i++)
				q.push(temp->children[i]);
		}

		vAll.push_back(v);
		v.clear();
	}

	return vAll;
}