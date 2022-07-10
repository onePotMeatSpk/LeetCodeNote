#pragma once
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//����347
//ǰ K ����ƵԪ��
//��ɣ�����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�

//˼·��
    //��һ����ͳ�Ƹ�Ԫ�ص�Ƶ��
    //�ڶ�������pair<Ԫ�أ� Ƶ��>�����η���С���ѣ���Ƶ��Ϊ�����ֵ�����Ѵ�С>kʱ���ͽ��Ѷ���Ƶ����С������
    //�������������ڶ���֮�󣬶������µľ���k��Ƶ����ߵģ��������ε�������

//�º���
class Comp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }

};

//������
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