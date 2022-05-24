#pragma once
#include<vector>
#include<queue>
using namespace std;
//����559
//��Ŀ��N ������������
//��Ŀ����������һ�� N �������ҵ��������ȡ�
		//��������ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�������
		//N �������밴����������л���ʾ��ÿ���ӽڵ��ɿ�ֵ�ָ�
		
//N��������
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


//����1������ݹ�
int maxDepth(Node* root)
{
	if (!root)	return 0;

	int depth = 0;
	for (int i = 0; i < root->children.size(); i++)
		depth = max(depth, maxDepth(root->children[i]));

	return depth + 1;
}

//����2���������
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