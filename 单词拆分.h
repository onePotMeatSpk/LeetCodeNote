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
