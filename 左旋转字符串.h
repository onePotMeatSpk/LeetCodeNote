#pragma once
#include<string>
using namespace std;
//��ָ Offer 58 - II. 
//����ת�ַ���
//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
			//���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��

//�������ַ�������Ϊǰ�������֣�ǰ��Ҫ����ת����
//�Ƚ������ַ�����ת��������ǰ���ͱ���ת�����ˣ����Ǵ�ʱ��ǰ���֡��󲿷ֵ��ڲ�Ҳ�ǵ���
//�ٷֱ���תǰ���֡��󲿷ֵ��ڲ���ʹ���ɵ���������



string reverseLeftWords(string s, int n)
{
	reverse(s.begin(), s.end());
	reverse(s.begin(), s.begin() + s.size() - n);
	reverse(s.begin() + s.size() - n, s.end());
	
	return s;
}