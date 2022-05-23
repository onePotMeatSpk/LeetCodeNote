#pragma once
#pragma once
#include<queue>
using namespace std;
//力扣117
//题目：填充每个节点的下一个右侧节点指针II
//题目描述：给定一个 二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。
            //填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

//与填充每个节点的下一个右侧节点指针的区别在于，由完美二叉树变成了二叉树
//代码不变

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