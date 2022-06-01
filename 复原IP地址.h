#pragma once
#include<vector>
#include<string>
using namespace std;

//力扣93
//题目：复原IP地址
//题目描述：有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
			//例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
			//给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
//			你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

//判断子串是否在[0,255]
bool isLegal(string s)
{
    int num = atoi(s.c_str());
    if (num >= 0 && num <= 255)  return 1;
    return 0;
}

//回溯
//index代表这层开始的坐标
//need代表IP地址还需要几部分
void back(string& s, vector<string>& v, vector<string>& ret, int index = 0, int need = 4)
{
    //IP地址4部分已经凑齐，且到达s末尾，说明该IP可用
    if (need == 0 && index == s.size())
    {
        string temp;
        for (int i = 0; i < 4; i++)
        {
            temp += v[i];
            temp += ".";
        }
        temp.pop_back();
        ret.push_back(temp);
        return;
    }
    //还没到达末尾，4部分就已经凑齐，失败
    if (need == 0)   return;
    //4部分还未凑齐，就已经到达末尾，失败
    if (index == s.size())   return;

    //如果该下标处为'0'
    //则该部分只能有一个'0'，不可以向后继续延伸，因为"011"、"001"等是不合法的
    if (s[index] == '0')
    {
        v.push_back("0");
        back(s, v, ret, index + 1, need - 1);
        v.pop_back();
    }
    //如果该下标处不为'0'
    //则可以以改下标为首，向后延伸一个最长3位的字符串
    else
        for (int i = 0; i < 3 && index + i < s.size(); i++)
        {
            //如果该子串不在[0,255]内，则显然不符合IP地址规则，故不做记录
            if (!isLegal(s.substr(index, i + 1)))    continue;
            //该子串在[0,255]内，继续向后凑剩余部分
            v.push_back(s.substr(index, i + 1));//记录该子串
            back(s, v, ret, index + i + 1, need - 1);//回溯
            v.pop_back();//恢复现场
        }
}

//主函数
vector<string> restoreIpAddresses(string s) {
    //s长度过短或者过长，可以不需要回溯，直接返回空
    if (s.size() < 4 || s.size() > 12)   return vector<string>();

    vector<string> v;
    vector<string> ret;
    back(s, v, ret);

    return ret;
}