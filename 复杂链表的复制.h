#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
//��Ŀ����������ĸ���
//��Ŀ��������ʵ�� copyRandomList ����������һ�����������ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬����һ�� random ָ��ָ�������е�����ڵ���� null��
// ��������ڵ�Ķ���
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

//���α���
//��һ�ν����������nextָ�롢����Դ�ڵ���½ڵ��ӳ��hashmap
//�ڶ��θ���hashmap���randomָ��
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

