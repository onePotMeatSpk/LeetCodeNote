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

//回溯
//s、v、vAll自不必说
//index是遍历s的当前索引，part是当前处在IP地址的第几部分
void dfsRestoreIpAddresses(const string& s, vector<string>& v, vector<string>& vAll, int index = 0, int part = 1) {
    //已经遍历到s末尾，并且已到IP第5部分，说明前面收集的IP地址可行
    if (part == 5 && index == s.size())
    {
        string temp = v[0] + "." + v[1] + "." + v[2] + "." + v[3];
        vAll.push_back(temp);
        return;
    }
    //仅有一个条件成立，说明前面收集的IP不可行
    if (part == 5 || index == s.size())  return;

    //以当前位为首，组成IP的第part部分
     
    //当前位是0
    //以0为首，组成IP的单独部分的话，该部分只能拥有0一位
    //0.1.1.1可行，00.1.1.1不可行
    if (s[index] == '0')
    {
        v.push_back("0");
        dfsRestoreIpAddresses(s, v, vAll, index + 1, part + 1);
        v.pop_back();
    }
    //当前位非0
    else
    {
        string ss;
        for (int i = 1; i <= 3 && index + i <= s.size(); i++)//一部分最多3位，还要注意下标越界
        {
            ss = s.substr(index, i);
            if (atoi(ss.c_str()) > 255)  break;//该部分最大255
            v.push_back(ss);//推入当前部分
            dfsRestoreIpAddresses(s, v, vAll, index + i, part + 1);
            v.pop_back();//恢复现场
        }
    }
}

//主函数
vector<string> restoreIpAddresses(string s) {
    vector<string> vAll;
    vector<string> v;
    dfsRestoreIpAddresses(s, v, vAll);
    return vAll;

}