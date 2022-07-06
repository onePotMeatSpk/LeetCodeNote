#pragma once
#include<string>
using namespace std;
//力扣151
//题目：颠倒字符串中的单词
//题干：给你一个字符串 s ，颠倒字符串中 单词 的顺序。
		//单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
		//
		//返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
		//
		//注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

//函数：移除字符串中多余空格，使得s中无前导空格、尾随空格，且两单词间仅有一个空格
void removeExtraSpace(string& s)
{
    int i = 0, j = 0;
    bool flagFirstChar = 0;
    while (j < s.size())
    {
        if (s[j] != ' ')
        {
            //遇到字符串中，第一个有效字符，则前方不需要加空格，直接加本单词的字符即可
            if (flagFirstChar == 0)
            {
                flagFirstChar = 1;
                s[i++] = s[j++];
            }
            //该字符不是本单词的第一个字符，则前方不需要加空格，直接加本单词的字符即可
            else if (s[j - 1] != ' ')
                s[i++] = s[j++];
            //该字符是本单词的第一个字符，且前方已经有单词，需要在该字符前加空格来分隔单词，然后再加本单词的字符
            else
            {
                s[i++] = ' ';
                s[i++] = s[j++];
            }
        }
        else
            j++;
    }

    //将多余的部分截去
    s.resize(i);
}

//函数:翻转字符串的[l, r)部分
void reverseString(string& s, int l, int r)
{
    int i = l, j = r - 1;
    for (; i < l + (r - l) / 2; i++, j--)
        swap(s[i], s[j]);
}

//主函数
string reverseWords(string s)
{
    //移除多余空格
    removeExtraSpace(s);

    //翻转整个字符串
    reverseString(s, 0, s.size());

    //翻转各单词
    for (int i = 0; i < s.size();)
    {
        int wordLen = 0;
        while (i < s.size() && s[i] != ' ')
        {
            i++;
            wordLen++;
        }

        reverseString(s, i - wordLen, i);
        i++;
    }

    return s;
}