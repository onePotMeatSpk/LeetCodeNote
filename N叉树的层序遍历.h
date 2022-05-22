#pragma once
#include<vector>
#include<queue>
using namespace std;
//����429
//��Ŀ��N�����Ĳ������
//��Ŀ����������һ�� N ������������ڵ�ֵ�Ĳ�����������������ң�����������


//���������ûɶ����

//N�����ṹ
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

//������
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