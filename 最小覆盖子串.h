#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
//力扣76
//题目：最小覆盖子串
//题目描述：给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
            //对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
            //如果 s 中存在这样的子串，我们保证它是唯一的答案。



//滑动窗口
//在本题中实现滑动窗口，主要确定如下三点：
//
//窗口内是什么？ 窗口就是子串
//
//如何移动窗口的起始位置？ 如果新增了当前字符后，t中所需字符已经凑齐，则要缩减窗口，直到所需字符有缺
//
//如何移动窗口的结束位置？ 窗口的结束位置就是遍历数组的指针，窗口的起始位置设置为数组的起始位置就可以了。


string minWindow(string s, string t) {
    //两个umap，umapS用来记录当前子串中已经收集到的t中字符的数量，umapT是用来查阅t中字符所需数量的字典
    unordered_map<char, int> umapS;
    unordered_map<char, int> umapT;
    //type2Collect是还需要收集的字符的种类，当某字符的数量集齐时，type2Collect--
    int type2Collect = 0;
    //统计type2Collect，初始化umapT
    for (int i = 0; i < t.size(); i++)
    {
        umapT[t[i]]++;
        if (umapT[t[i]] == 1)
            type2Collect++;
    }

    //start是最小子串的开始坐标
    int minLen = INT_MAX, l = 0, r = 0, start = 0;
    for (int r = 0; r < s.size(); r++)
    {
        //新增字符不属于t，则不计数
        if (umapT.find(s[r]) == umapT.end())
            continue;
        //新增字符不属于t，则计数
        umapS[s[r]]++;
        //当新增字符导致该字符的数量集齐时，type2Collect--
        if (umapS[s[r]] == umapT[s[r]])
            type2Collect--;

        //所有字符，均已经集齐，可以缩减窗口
        while (type2Collect == 0)
        {
            //看看当前子串，是不是更小的子串
            int len = r - l + 1;
            if (len < minLen)
            {
                minLen = len;
                start = l;
            }

            //缩减字符不属于t，则只缩减，不计数
            if (umapT.find(s[l]) == umapT.end())
                l++;
            //缩减字符属于t，则缩减并计数
            else
            {
                //当缩减字符，导致该字符的数量有缺时，type2Collect--
                umapS[s[l]]--;
                if (umapS[s[l]] < umapT[s[l]])
                    type2Collect++;
                l++;
            }
        }
    }

    //没有合适的子串
    if (minLen == INT_MAX)
        return "";
    //有合适的子串
    else
        return s.substr(start, minLen);
}