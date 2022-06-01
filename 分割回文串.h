#pragma once
#include<string>
#include<vector>
using namespace std;
//����131
//��Ŀ���ָ���Ĵ�
//��Ŀ����������һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����

//�ж��ַ����Ƿ����
bool isPali(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i++] == s[j--])    continue;
        else    return 0;
    }
    return 1;
}

//���ݺ���
void back(string& s, int index, vector<string>& v, vector<vector<string>>& ret) {
    //�ܵ����˵��ǰ����Ӵ�������
    if (index == s.size())
    {
        ret.push_back(v);
        return;
    }

    //��indexΪʼ�齨һ���Ӵ����������
    for (int i = 0; i < s.size() - index; i++)
    {
        //�����Ӵ������ģ����·��ͨ
        if (!isPali(s.substr(index, i + 1)))    continue;
        //�����Ӵ����ģ��򽫸��Ӵ���¼�����ڸ��Ӵ�֮���齨�µ��Ӵ�
        v.push_back(s.substr(index, i + 1));//��¼�Ӵ�
        back(s, index + i + 1, v, ret);//����
        v.pop_back();//�ָ��ֳ�
    }
}

//������
vector<vector<string>> partition(string s) {
    vector<string> v;
    vector<vector<string>> ret;
    back(s, 0, v, ret);
    return ret;
}