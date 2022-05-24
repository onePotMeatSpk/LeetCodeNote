#pragma once
#include<vector>
#include<queue>
using namespace std;
//力扣559
//题目：N 叉树的最大深度
//题目描述：给定一个 N 叉树，找到其最大深度。
		//最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
		//N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔
		
//N叉树定义
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


//方法1：后序递归
int maxDepth(Node* root)
{
	if (!root)	return 0;

	int depth = 0;
	for (int i = 0; i < root->children.size(); i++)
		depth = max(depth, maxDepth(root->children[i]));

	return depth + 1;
}

//方法2：层序遍历
int maxDepth(Node* root) {
	if (!root)	return 0;

	queue<Node*> q;
	q.push(root);

	int depth = 0;
	while (!q.empty())
	{
		depth++;
		int count = q.size();
		while (count--)
		{
			Node* temp = q.front();
			q.pop();

			for (int i = 0; i < temp->children.size(); i++)
				q.push(temp->children[i]);
		}
	}

	return depth;
}