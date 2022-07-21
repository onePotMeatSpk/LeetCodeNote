#pragma once
#include<vector>
#include<unordered_set>
using namespace std;

//力扣139
//题目：单词拆分
//题目描述：给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//			注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

//dp
//dp[j]：字符串s的前j个字符可拆分
//dp[0] = 1：字符串如果可拆分，最后一定会被拆分为空字符串，所以dp[0] = 1
//递推公式：如果字符串以i结尾，并且去除i以后仍然可拆分，那字符串必然可拆分
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> uset(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);

    dp[0] = true;

    for (int j = 1; j <= s.size(); j++)
        for (int i = 1; i <= j; i++)
        {
            string sub = s.substr(j - i, i);
            if (dp[j - i] == true && uset.find(sub) != uset.end())
                dp[j] = true;
        }

    return dp[s.size()];

}
