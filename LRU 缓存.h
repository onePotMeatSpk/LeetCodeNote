#pragma once
#include<unordered_map>
#include<list>
using namespace std;

//力扣146
//题目：LRU缓存
//题目描述：请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
            //实现 LRUCache 类：
            //LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
            //int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 - 1 。
            //void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key - value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
            //函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


//思路：
//双向链表list<pair<int, int>>，存储<key, value>键值对
//哈希表unordered_map<int, list<int, int>::iterator>，存储key相应的链表节点

//实现方式1：链表使用list
class LRUCache {
public:

    int cap = 0;
    int size = 0;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> map;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        auto it = map.find(key);
        //缓存中无该元素
        if (it == map.end())   return -1;
        //缓存中有该元素，则将该元素节点放到末尾，再返回其值
        //处理l
        l.push_back(pair<int, int>(key, it->second->second));
        l.erase(it->second);
        //处理map
        map[key] = (--l.end());
        return (--l.end())->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        //缓存中无该元素
        if (it == map.end())
        {
            //缓存已满，需要删除最久未使用的元素，并加入新元素
            if (size == cap)
            {
                //删除最久未使用的
                //处理map
                auto itOld = l.begin();
                map.erase(map.find(itOld->first));
                //处理l
                l.pop_front();

                //加入新元素
                //处理l
                l.push_back(pair<int, int>(key, value));
                //处理map
                map[key] = --l.end();
            }
            //缓存未满，只需要加入新元素
            else
            {
                //更新size
                size++;

                //加入新元素
                //处理l
                l.push_back(pair<int, int>(key, value));
                //处理map
                map[key] = --l.end();
            }
        }
        //缓存中有该元素
        //将该元素值更改，并迁入末尾
        else
        {
            //删除旧节点
            l.erase(it->second);
            //添加新节点
            l.push_back(pair<int, int>(key, value));
            //更改map
            map[key] = --l.end();
        }
    }
};

//实现方式1：自己造轮子
class LRUCache {
public:
    struct Node
    {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node() :val(0), prev(NULL), next(NULL) {}
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };

    struct List
    {
        Node* head;//虚头部
        Node* tail;//虚尾部

        List() : head(new Node(0, 0)), tail(new Node(0, 0)) {
            //初始化：头尾成环
            head->next = tail;
            head->prev = tail;
            tail->prev = head;
            tail->next = head;
        }

        //尾结点
        Node* back_node()
        {
            return tail->prev;
        }

        //头结点
        Node* front_node()
        {
            return head->next;
        }

        //删除某节点
        void del_node(Node* node)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }

        //头插新节点
        void push_front(Node* node)
        {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }

        //尾删
        void pop_back()
        {
            Node* nodePop = tail->prev;
            nodePop->prev->next = tail;
            tail->prev = nodePop->prev;
            delete nodePop;
        }
    };


    int size;
    int cap;
    List list;
    unordered_map<int, Node*> map;

    LRUCache(int capacity) : size(0), cap(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end())  return -1;

        int tempValue = map.find(key)->second->val;
        list.del_node(map.find(key)->second);
        list.push_front(new Node(key, tempValue));
        map[key] = list.front_node();
        return map[key]->val;
    }

    void put(int key, int value) {
        if (map.find(key) == map.end())
        {
            if (size == cap)
            {
                map.erase(list.back_node()->key);
                list.pop_back();

                list.push_front(new Node(key, value));
                map[key] = list.front_node();
            }
            else
            {
                list.push_front(new Node(key, value));
                map[key] = list.front_node();
                size++;
            }
        }
        else
        {
            list.del_node(map.find(key)->second);

            list.push_front(new Node(key, value));
            map[key] = list.front_node();
        }
    }
};