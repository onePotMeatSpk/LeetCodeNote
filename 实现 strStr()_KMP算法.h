#pragma once
#include<string>
#include<vector>
using namespace std;
//力扣28
//题目：实现 strStr()
//题干：给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

//思路：KMP算法

//函数：获得next数组，next[i]是[0, i]的最长相等前缀的长度
vector<int> getNext(string& s)
{
    vector<int> next(s.size(), 0);

    //i是后缀末尾，j是前缀末尾，next[i]是[0, i]的最长相等前缀的长度
    int j = 0;
    for (int i = 1; i < s.size(); i++)//i必须从1开始！因为仅有一个字符的字符串，是不存在前、后缀的，所以必定next[0] = 0
    {
        //s[i]与s[j]的比较，是建立在s[i - 1] == s[j - 1]的基础上，换言之[0, j - 1]为[0, i - 1]的最长相等前缀
        
        //s[i] != s[j]
        //说明[0, j]不可能为[0, i]的最长相等前缀
        //但[0, j - 1]为[0, i - 1]的最长相等前缀，而[0, j - 1]又有其自己的最长相等前缀，长度是next[j - 1]，该前缀就是[0, next[j - 1] - 1]
        //因为[0, next[j - 1] - 1]是[0, j - 1]的前缀，又因为[0, j - 1]是[0, i - 1]的前缀，则[0, next[j - 1] - 1]是[0, i - 1]的前缀
        //所以当s[i] != s[j]时，可以拿s[next[j - 1]]与s[i]来作比较
        //故而j = next[j - 1]，以拿s[next[j - 1]]与s[i]来作比较
        while (j > 0 && s[i] != s[j])
            j = next[j - 1];

        //s[i] == s[j]
        //说明在s[i - 1] == s[j - 1]的基础上，最长相等前缀又更长一节，则[0, j]为[0, i]的最长相等前缀
        //①既然[0, j]为[0, i]的最长相等前缀，那该前缀长度就是j+1
        //②而且，在i + 1处，还要以[0, j]是[0, i]的最长相等前缀为基础，再来判断[0, j + 1]是否[0, i + 1]的最长相等前缀
        //故而next[i] = ++j，以成全①②
        if (s[i] == s[j])
            next[i] = ++j;
        //s[i] != s[j]
        //能跳出上方while，且s[i] != s[j]，说明j == 0
        //j == 0 ，而且s[i] != s[j]，说明s[i] != s[0]，那么说明[0, i]不具有最长相等前缀
        //故而next[i] = 0
        else
            next[i] = 0;
    }

    return next;
}

int strStr(string haystack, string needle)
{
    //模式串为空，返回0，与库函数strstr()贴合
    if (needle.size() == 0)
        return 0;

    //取得模式串的next数组
    vector<int> next = getNext(needle);

    //开始KMP比较
    //i遍历样本串，j遍历模式串
    int j = 0;
    for (int i = 0; i < haystack.size();)
    {
        //某位匹配成功
        if (haystack[i] == needle[j])
        {
            //则i、j均往后移，以供下次比较
            i++;
            j++;
            //如果j已经到头，说明整个模式串都匹配成功了，可以return
            if (j == needle.size())
                return i - j;
        }
        //某位匹配成功
        else
        {
            //则从模式串的最长相等前缀的下一位，再开始比较
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];

            //如果模式串的最长相等前缀的下一位比较成功，则不必再从模式串的0位开始重新比较了，而是从这下一位，继续向后匹配样本串
            if (haystack[i] == needle[j])
                j++;
            //不管模式串有没有匹配成功，样本串都要向后推进
            i++;
        }
    }

    //匹配失败
    return -1;
}