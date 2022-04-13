#pragma once
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//题目：根据字符出现频率排序
//题目描述：给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
//			返回 已排序的字符串 。如果有多个答案，返回其中任何一个。

string frequencySort(string s) {
    string newS = "";
    unordered_map<char, int> um;
    int countMax = 0;//各字母出现次数中的最大次数
    for (int i = 0; i < s.size(); i++)//统计次数
        countMax = max(countMax, ++um[s[i]]);

    vector<vector<char>> v(countMax + 1, vector<char>());//桶，该桶按照字母的出现次数，从小到大记录字母
    for (auto it = um.begin(); it != um.end(); it++)
        if (it->second)  v[it->second].push_back(it->first);//如果某字母出现次数非0，就把它放入桶中

    auto it = newS.end();
    for (int i = countMax; i >= 0; i--)//按出现次数，从大到小遍历
        if (!v[i].empty())
            for (int j = 0; j < v[i].size(); j++)//更新字符串
            {
                newS.insert(it, i, v[i][j]);
                it = newS.end();
            }

    return newS;
}