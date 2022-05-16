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
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= s.size(); j++)
        for (int i = 0; i < wordDict.size(); i++)
        {
            string word = wordDict[i];
            int len = word.size();
            if (len <= j && s.substr(j - len, len) == word && dp[j - len])
                dp[j] = 1;
        }

    return dp[s.size()];
}
