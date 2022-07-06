#pragma once
#include<string>
using namespace std;
//����151
//��Ŀ���ߵ��ַ����еĵ���
//��ɣ�����һ���ַ��� s ���ߵ��ַ����� ���� ��˳��
		//���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����
		//
		//���� ���� ˳��ߵ��� ���� ֮���õ����ո����ӵĽ���ַ�����
		//
		//ע�⣺�����ַ��� s�п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո񡣷��صĽ���ַ����У����ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�

//�������Ƴ��ַ����ж���ո�ʹ��s����ǰ���ո�β��ո��������ʼ����һ���ո�
void removeExtraSpace(string& s)
{
    int i = 0, j = 0;
    bool flagFirstChar = 0;
    while (j < s.size())
    {
        if (s[j] != ' ')
        {
            //�����ַ����У���һ����Ч�ַ�����ǰ������Ҫ�ӿո�ֱ�Ӽӱ����ʵ��ַ�����
            if (flagFirstChar == 0)
            {
                flagFirstChar = 1;
                s[i++] = s[j++];
            }
            //���ַ����Ǳ����ʵĵ�һ���ַ�����ǰ������Ҫ�ӿո�ֱ�Ӽӱ����ʵ��ַ�����
            else if (s[j - 1] != ' ')
                s[i++] = s[j++];
            //���ַ��Ǳ����ʵĵ�һ���ַ�����ǰ���Ѿ��е��ʣ���Ҫ�ڸ��ַ�ǰ�ӿո����ָ����ʣ�Ȼ���ټӱ����ʵ��ַ�
            else
            {
                s[i++] = ' ';
                s[i++] = s[j++];
            }
        }
        else
            j++;
    }

    //������Ĳ��ֽ�ȥ
    s.resize(i);
}

//����:��ת�ַ�����[l, r)����
void reverseString(string& s, int l, int r)
{
    int i = l, j = r - 1;
    for (; i < l + (r - l) / 2; i++, j--)
        swap(s[i], s[j]);
}

//������
string reverseWords(string s)
{
    //�Ƴ�����ո�
    removeExtraSpace(s);

    //��ת�����ַ���
    reverseString(s, 0, s.size());

    //��ת������
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