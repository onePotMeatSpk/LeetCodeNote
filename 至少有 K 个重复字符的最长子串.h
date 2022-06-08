#pragma once
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//����395
//������ K ���ظ��ַ�����Ӵ�
//����һ���ַ��� s ��һ������ k �������ҳ� s �е���Ӵ��� Ҫ����Ӵ��е�ÿһ�ַ����ִ����������� k ��������һ�Ӵ��ĳ��ȡ�


//���η���
	//�κ��ַ����У�ֻҪ��������������k����ĸ���Ͳ�������ĿҪ��
	//���ԣ�ʹ����������k����ĸ�����ַ����ָ�Ϊ�Ӵ����ٿ������Ӵ��Ƿ������ĿҪ�󣨷��Σ�
int split(string& s, int& k, int l, int r)
{
	//[l, r]�Ӵ�����С��k����϶���������ĿҪ��
	if (r - l + 1 < k)	return 0;

	unordered_map<char, int> map;
	unordered_set<char> set;

	//ͳ��[l, r]�Ӵ��У�����ĸ����
	for (int i = l; i <= r; i++)
		map[s[i]]++;

	//�ҳ�[l, r]�Ӵ��У���������k����ĸ
	for (auto it = map.begin(); it != map.end(); it++)
		if (it->second < k)	set.insert(it->first);

	//[l, r]�Ӵ��У�û����������k����ĸ����[l,r]�Ӵ�����Ҫ��
	if (set.empty())	return r - l + 1;

	//ͳ��[l, r]�Ӵ��У���������k����ĸ������
	vector<int> vec;
	for (int i = l; i <= r; i++)
		if (set.find(s[i]) != set.end())	vec.push_back(i);

	//�κ��ַ����У�ֻҪ��������������k����ĸ���Ͳ�������ĿҪ��
	//���ԣ�ʹ����������k����ĸ�����ַ����ָ�Ϊ�Ӵ����ٿ������Ӵ��Ƿ������ĿҪ��
	int lenMax = 0, len;
	int right, left;
	//ǰ�漸���Ӵ�
	for (int i = 0; i < vec.size(); i++)
	{
		left = i == 0 ? l : vec[i - 1] + 1;
		right = vec[i] - 1;
		len = split(s, k, left, right);
		lenMax = lenMax >= len ? lenMax : len;
	}
	//���һ���Ӵ�
	if (vec[vec.size() - 1] != r)
	{
		left = vec[vec.size() - 1] + 1;
		right = r;
		len = split(s, k, left, right);
		lenMax = lenMax >= len ? lenMax : len;
	}

	return lenMax;
}


int longestSubstring(string s, int k) {
	return split(s, k, 0, s.size() - 1);
}