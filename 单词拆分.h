#pragma once
#include<vector>
#include<unordered_set>
using namespace std;

//����139
//��Ŀ�����ʲ��
//��Ŀ����������һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣�����ж��Ƿ���������ֵ��г��ֵĵ���ƴ�ӳ� s ��
//			ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�

//dp
//dp[j]���ַ���s��ǰj���ַ��ɲ��
//dp[0] = 1���ַ�������ɲ�֣����һ���ᱻ���Ϊ���ַ���������dp[0] = 1
//���ƹ�ʽ������ַ�����i��β������ȥ��i�Ժ���Ȼ�ɲ�֣����ַ�����Ȼ�ɲ��
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
