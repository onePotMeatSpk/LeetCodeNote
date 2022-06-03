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