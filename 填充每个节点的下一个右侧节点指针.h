#pragma once
#include<queue>
using namespace std;

//树节点定义
struct Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//层序遍历
Node* connect(Node* root) {
    if (!root)   return root;

    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            Node* temp = q.front();
            q.pop();

            temp->next = count ? q.front() : NULL;

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return root;
}