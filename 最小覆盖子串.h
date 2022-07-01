#pragma once
#include<vector>
#include<unordered_map>
using namespace std;
//����76
//��Ŀ����С�����Ӵ�
//��Ŀ����������һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
            //���� t ���ظ��ַ�������Ѱ�ҵ����ַ����и��ַ��������벻���� t �и��ַ�������
            //��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�



//��������
//�ڱ�����ʵ�ֻ������ڣ���Ҫȷ���������㣺
//
//��������ʲô�� ���ھ����Ӵ�
//
//����ƶ����ڵ���ʼλ�ã� ��������˵�ǰ�ַ���t�������ַ��Ѿ����룬��Ҫ�������ڣ�ֱ�������ַ���ȱ
//
//����ƶ����ڵĽ���λ�ã� ���ڵĽ���λ�þ��Ǳ��������ָ�룬���ڵ���ʼλ������Ϊ�������ʼλ�þͿ����ˡ�


string minWindow(string s, string t) {
    //����umap��umapS������¼��ǰ�Ӵ����Ѿ��ռ�����t���ַ���������umapT����������t���ַ������������ֵ�
    unordered_map<char, int> umapS;
    unordered_map<char, int> umapT;
    //type2Collect�ǻ���Ҫ�ռ����ַ������࣬��ĳ�ַ�����������ʱ��type2Collect--
    int type2Collect = 0;
    //ͳ��type2Collect����ʼ��umapT
    for (int i = 0; i < t.size(); i++)
    {
        umapT[t[i]]++;
        if (umapT[t[i]] == 1)
            type2Collect++;
    }

    //start����С�Ӵ��Ŀ�ʼ����
    int minLen = INT_MAX, l = 0, r = 0, start = 0;
    for (int r = 0; r < s.size(); r++)
    {
        //�����ַ�������t���򲻼���
        if (umapT.find(s[r]) == umapT.end())
            continue;
        //�����ַ�������t�������
        umapS[s[r]]++;
        //�������ַ����¸��ַ�����������ʱ��type2Collect--
        if (umapS[s[r]] == umapT[s[r]])
            type2Collect--;

        //�����ַ������Ѿ����룬������������
        while (type2Collect == 0)
        {
            //������ǰ�Ӵ����ǲ��Ǹ�С���Ӵ�
            int len = r - l + 1;
            if (len < minLen)
            {
                minLen = len;
                start = l;
            }

            //�����ַ�������t����ֻ������������
            if (umapT.find(s[l]) == umapT.end())
                l++;
            //�����ַ�����t��������������
            else
            {
                //�������ַ������¸��ַ���������ȱʱ��type2Collect--
                umapS[s[l]]--;
                if (umapS[s[l]] < umapT[s[l]])
                    type2Collect++;
                l++;
            }
        }
    }

    //û�к��ʵ��Ӵ�
    if (minLen == INT_MAX)
        return "";
    //�к��ʵ��Ӵ�
    else
        return s.substr(start, minLen);
}