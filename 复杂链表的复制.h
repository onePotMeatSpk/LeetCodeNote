#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
//题目：复杂链表的复制
//题目描述：请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
// 复杂链表节点的定义
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//两次遍历
//第一次建立链表、完成next指针、建立源节点和新节点的映射hashmap
//第二次根据hashmap完成random指针
//O(N),O(N)
Node* copyRandomList(Node* head) {
    if (!head)   return NULL;
    unordered_map<Node*, Node*> reflect;
    Node* cur = head;
    Node* pre = NULL;
    Node* newCur;
    while (cur)
    {
        newCur = new Node(cur->val);
        reflect.insert(make_pair(cur, newCur));
        if (pre) pre->next = newCur;
        pre = newCur;
        cur = cur->next;
    }

    cur = head;
    while (cur)
    {
        reflect[cur]->random = reflect[cur->random];
        cur = cur->next;
    }
    return reflect[head];
}

