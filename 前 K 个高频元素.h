#pragma once
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//力扣347
//前 K 个高频元素
//题干：给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

//思路：
    //第一步，统计各元素的频率
    //第二步，将pair<元素， 频率>，依次放入小顶堆，以频率为排序键值，当堆大小>k时，就将堆顶（频率最小）弹出
    //第三步，经过第二步之后，堆中留下的就是k个频率最高的，将其依次弹出即可

//仿函数
class Comp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }

};

//主函数
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i++)
        umap[nums[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        pq.push(*it);
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ret;
    while (!pq.empty())
    {
        ret.push_back(pq.top().first);
        pq.pop();
    }

    return ret;
}