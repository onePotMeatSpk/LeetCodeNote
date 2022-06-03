#pragma once
#include<unordered_map>
using namespace std;
//力扣460
//题目：LFU缓存
//题目描述：请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。
        //实现 LFUCache 类：
        //
        //LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
        //int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 - 1 。
        //void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量 capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
        //为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
        //
        //当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。
        //
        //函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。




//思路：
//节点结构体Node：存储key、value，以及该节点被用到的频率信息freq
//同频率节点集合FreqList：存储具有相同频率的节点，本质是一个双向链表
//整形变量size：缓存中key的数量
//整形变量cap：缓存容量
//整形变量minFreq：缓存中，最少使用到的key的频率
//哈希表mapNode：存储(key, Node*)对，可以通过key，找到存储key的节点
//哈希表mapFreq：存储(freq, FreqList*)对，可以通过使用次数freq，找到存储使用次数为freq的节点集合


class LFUCache {
public:
    //节点结构体，用来存储(key, value)信息
    struct Node {
        int key = 0;
        int val = 0;
        int freq = 0;//该key被用到的频率
        Node* prev = NULL;
        Node* next = NULL;

        Node()
        {
        }

        Node(int k, int v)
        {
            key = k;
            val = v;
            freq = 1;
            prev = NULL;
            next = NULL;
        }
    };

    //同频率节点集合，存储具有相同频率的信息
    struct FreqList {
        int freq = 0;
        Node* head = NULL;
        Node* tail = NULL;

        FreqList(int f)
        {
            freq = f;
            head = new Node();
            tail = new Node();
            head->next = tail;
            head->prev = tail;
            tail->next = head;
            tail->prev = head;
        }

        //将新节点插入到集合前方
        void addToFront(Node* p)
        {
            p->next = head->next;
            p->prev = head;
            head->next = p;
            p->next->prev = p;
        }

        //将节点从集合中取出
        void getNode(Node* p)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }

        //将节点从集合中删除
        void delNode(Node* p)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }

        //返回除head、tail之外的最后一个元素
        Node* back()
        {
            return tail->prev;
        }

        //判断集合是否为空
        bool empty()
        {
            return head->next == tail;
        }
    };




    int size;//缓存中key的数量
    int cap;//缓存容量
    int minFreq;//缓存中，最少使用到的key的频率
    unordered_map<int, Node*> mapNode;
    unordered_map<int, FreqList*> mapFreq;

    LFUCache(int capacity) {
        size = 0;
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        //缓存中没有key
            //return -1
        //缓存中有key节点
            //改变key节点的频率
            //改变key节点的集合
            //根据情况，改变最小频率

        auto itNode = mapNode.find(key);
        //缓存中没有key
        if (itNode == mapNode.end())
            //return -1
            return -1;
        //缓存中有key节点
        else
        {
            //改变key节点的频率
            itNode->second->freq++;
            //改变key节点的集合
            changeFreqList(itNode->second, 1);
            //如果key节点的旧频率是最小频率，且其旧频率集合已经不存在了，那么key节点的新频率就是最小频率
            if (itNode->second->freq - 1 == minFreq && mapFreq.find(minFreq) == mapFreq.end())
                minFreq = itNode->second->freq;
        }
        return itNode->second->val;
    }

    void put(int key, int value) {
        //如果容量为0，直接返回
        //缓存中没有key
            //满
                //删除最小频率节点
            //创建新节点
            //更新mapNode
            //改变新节点的集合
            //改变最小频率为1
            //更新size
        //缓存中有key
            //改变节点的频率
            //改变节点的集合
            //根据情况，改变最小频率




        //如果容量为0，直接返回
        if (cap == 0)    return;

        auto itNode = mapNode.find(key);
        //缓存中没有key
        if (itNode == mapNode.end())
        {
            //满
            if (size == cap)
            {
                //删除最小频率节点
                delLeastFreq();
            }
            //创建新节点
            Node* pNode = new Node(key, value);
            //更新mapNode
            mapNode[key] = pNode;
            //改变新节点的集合
            changeFreqList(pNode, 0);
            //改变最小频率为1
            minFreq = 1;
            //更新size
            size = size == cap ? size : size + 1;
        }
        //缓存中有key
        else
        {
            //改变节点的值
            itNode->second->val = value;
            //改变节点的频率
            itNode->second->freq++;
            //改变节点的集合
            changeFreqList(itNode->second, 1);
            //如果key节点的旧频率是最小频率，且其旧频率集合已经不存在了，那么key节点的新频率就是最小频率
            if (itNode->second->freq - 1 == minFreq && mapFreq.find(minFreq) == mapFreq.end())
                minFreq = itNode->second->freq;
        }
    }


    //删除最小频率节点
    void delLeastFreq()
    {
        //找到最小频率集合
        //找到最小频率集合尾部节点
        //在mapNode中，删除最小频率集合尾部节点的信息
        //删除最小频率集合尾部
        //最小频率集合如果为空，就将其删除，并更新mapFreq


        //找到最小频率集合
        FreqList* pFreqList = mapFreq[minFreq];
        //找到最小频率集合尾部节点
        Node* pDel = pFreqList->back();
        //在mapNode中，删除最小频率集合尾部节点的信息
        mapNode.erase(mapNode.find(pDel->key));
        //删除最小频率集合尾部
        pFreqList->delNode(pDel);
        //最小频率集合如果为空，就将其删除，并更新mapFreq
        if (pFreqList->empty())
        {
            mapFreq.erase(mapFreq.find(pFreqList->freq));
            delete pFreqList;
        }
    }


    //改变某节点的所在集合
    void changeFreqList(Node* p, bool flag)
    {
        //p是旧节点，已经在集合中
        if (flag == 1)
        {
            auto itFreqNew = mapFreq.find(p->freq);
            auto itFreqOld = mapFreq.find(p->freq - 1);

            //没有新频率对应的集合
            if (itFreqNew == mapFreq.end())
            {
                //创建新集合
                FreqList* pFreqList = new FreqList(p->freq);
                //更新mapFreq
                mapFreq[p->freq] = pFreqList;
                //将p从旧集合中取出
                itFreqOld->second->getNode(p);
                //将p放入新集合
                pFreqList->addToFront(p);
            }
            //有新频率对应的集合
            else
            {
                //将p从旧集合中取出
                itFreqOld->second->getNode(p);
                //将p放入新集合
                itFreqNew->second->addToFront(p);
            }

            //旧集合如果为空，就将其删除，并更新mapFreq
            if (itFreqOld->second->empty())
            {
                FreqList* pFreqListOld = itFreqOld->second;
                mapFreq.erase(mapFreq.find(pFreqListOld->freq));
                delete pFreqListOld;
            }
        }
        //p是新建节点，不在集合中
        else
        {
            auto itFreqNew = mapFreq.find(1);

            //没有新频率对应的集合
            if (itFreqNew == mapFreq.end())
            {
                //创建新集合
                FreqList* pFreqList = new FreqList(p->freq);
                //更新mapFreq
                mapFreq[p->freq] = pFreqList;
                //将p放入新集合
                pFreqList->addToFront(p);

            }
            //有新频率对应的集合
            else
            {
                //将p放入集合
                itFreqNew->second->addToFront(p);
            }
        }
    }
};