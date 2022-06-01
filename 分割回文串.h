#pragma once
#include<string>
#include<vector>
using namespace std;
//力扣131
//题目：分割回文串
//题目描述：给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

//判断字符串是否回文
bool isPali(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i++] == s[j--])    continue;
        else    return 0;
    }
    return 1;
}

//回溯函数
void back(string& s, int index, vector<string>& v, vector<vector<string>>& ret) {
    //能到最后，说明前面的子串都回文
    if (index == s.size())
    {
        ret.push_back(v);
        return;
    }

    //以index为始组建一个子串，向后伸张
    for (int i = 0; i < s.size() - index; i++)
    {
        //若该子串不回文，则此路不通
        if (!isPali(s.substr(index, i + 1)))    continue;
        //若该子串回文，则将该子串记录，并在该子串之后，组建新的子串
        v.push_back(s.substr(index, i + 1));//记录子串
        back(s, index + i + 1, v, ret);//回溯
        v.pop_back();//恢复现场
    }
}

//主函数
vector<vector<string>> partition(string s) {
    vector<string> v;
    vector<vector<string>> ret;
    back(s, 0, v, ret);
    return ret;
}