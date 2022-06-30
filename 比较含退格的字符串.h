#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣844
//题目：比较含退格的字符串
//题目描述：给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
//			注意：如果对空文本输入退格字符，文本继续为空。


//先对字符串进行处理，得到有效的输入字符串
//      使用双指针法：设l为慢指针，r为快指针，r遍历检查处理前的字符串，l用来接收有效字符串中的字符
//                    若r处非 #，则这个字符是一次有效输入，则将其值赋给l处，l++表示有效字符串变长一位，r++检查下一个字符
//                    若r处是 #，则这个字符不是一次有效输入，并且还会将之前的一次有效输入抹杀，则l--表示有效字符串变短一位，r++检查下一个字符
//然后再对两字符串作比较
bool backspaceCompare(string s, string t) {
    //双指针法，将s中#去除，得到有效的s
    //l为慢指针，r为快指针
    int l = 0, r = 0;
    while (r < s.size())
    {
        if (s[r] != '#')
            s[l++] = s[r++];
        else
        {
            if (l > 0)
                l--;
            r++;
        }
    }
    int lenS = l;

    //双指针法，将t中#去除，得到有效的t
    l = 0, r = 0;
    while (r < t.size())
    {
        if (t[r] != '#')
            t[l++] = t[r++];
        else
        {
            if (l > 0)
                l--;
            r++;
        }
    }
    int lenT = l;

    //如果s、t长度不同，如不同，则返回
    if (lenS != lenT)
        return false;

    //依次判断s、t的各个字符，如有不同，则返回
    for (int i = 0; i < lenS; i++)
        if (s[i] != t[i])
            return false;

    return true;
}