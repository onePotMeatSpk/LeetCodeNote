#pragma once
#include<vector>
#include<unordered_set>
using namespace std;

//题目：单拆分
//题目描述：给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//			注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

//思路：动态规划，如果以j-1结尾的字符串可拆分，且以j为首、i为尾的字符串位于字典中，则以i结尾的字符串可拆分
//dp，O(N^2),O(N)
bool wordBreak(string s, vector<string>& wordDict) {
    //将字典放到哈希set中，使确定子字符串是否位于字典中的操作，复杂度降低为O(1)
    unordered_set<string> setWord(wordDict.begin(), wordDict.end());

    //初始化dp数组
    //dp[i+1]表示以i结尾的字符串是否可拆分
    vector<bool> dp(s.size() + 1, 0);
    dp[0] = 1;

    //动态规划主循环体
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j <= i; j++)
            //如果以j-1结尾的字符串可拆分，且以j为首、i为尾的字符串位于字典中
            if (dp[j] && setWord.find(s.substr(j, i - j + 1)) != setWord.end())
            {
                dp[i + 1] = 1;//则以i结尾的字符串可拆分
                break;
            }

    return dp[s.size()];
}
