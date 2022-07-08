#pragma once
#include<string>
#include<vector>
using namespace std;
//力扣459
//题目：重复的子字符串
//题干：给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

//KMP算法
//如果len % (len - (next[len - 1])) == 0 ，则说明(数组长度 - 最长相等前后缀的长度) 正好可以被 数组的长度整除，说明有该字符串有重复的子字符串。
//数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。

//函数：获得next数组，next[i]是[0, i]的最长相等前缀的长度
vector<int> getNext(string s)
{
    vector<int> next(s.size(), 0);

    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = next[j - 1];

        if (s[i] == s[j])
            next[i] = ++j;
    }

    return next;
}

//主函数
bool repeatedSubstringPattern(string s)
{
    int len = s.size();
    vector<int> next = getNext(s);
    for (int i : next)

    //核心
    if (next[len - 1] != 0 && (len % (len - next[len - 1]) == 0))
        return 1;
    else
        return 0;
}