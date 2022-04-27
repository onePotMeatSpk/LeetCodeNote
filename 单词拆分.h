#pragma once
#include<vector>
#include<unordered_set>
using namespace std;

//��Ŀ�������
//��Ŀ����������һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣�����ж��Ƿ���������ֵ��г��ֵĵ���ƴ�ӳ� s ��
//			ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�

//˼·����̬�滮�������j-1��β���ַ����ɲ�֣�����jΪ�ס�iΪβ���ַ���λ���ֵ��У�����i��β���ַ����ɲ��
//dp��O(N^2),O(N)
bool wordBreak(string s, vector<string>& wordDict) {
    //���ֵ�ŵ���ϣset�У�ʹȷ�����ַ����Ƿ�λ���ֵ��еĲ��������ӶȽ���ΪO(1)
    unordered_set<string> setWord(wordDict.begin(), wordDict.end());

    //��ʼ��dp����
    //dp[i+1]��ʾ��i��β���ַ����Ƿ�ɲ��
    vector<bool> dp(s.size() + 1, 0);
    dp[0] = 1;

    //��̬�滮��ѭ����
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j <= i; j++)
            //�����j-1��β���ַ����ɲ�֣�����jΪ�ס�iΪβ���ַ���λ���ֵ���
            if (dp[j] && setWord.find(s.substr(j, i - j + 1)) != setWord.end())
            {
                dp[i + 1] = 1;//����i��β���ַ����ɲ��
                break;
            }

    return dp[s.size()];
}
