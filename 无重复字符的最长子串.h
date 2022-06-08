#pragma once
#include<string>
#include<unordered_set>
using namespace std;
//����3
//���ظ��ַ�����Ӵ�
//����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

//˼·����������
	//ʲô�ǻ������ڣ�
	//��ʵ����һ������, ���������е� abcabcbb������������У����ڣ�Ϊ abc ������ĿҪ�󣬵��ٽ��� a�����б���� abca����ʱ������Ҫ�����ԣ�����Ҫ�ƶ�������У�
	//����ƶ���
	//����ֻҪ�Ѷ��е���ߵ�Ԫ���Ƴ������ˣ�ֱ��������ĿҪ��
	//һֱά�������Ķ��У��ҳ����г�����ĳ���ʱ�������
	//O(n)O(n)
int lengthOfLongestSubstring(string s) {
	if (s.empty())	return 0;

	int l = 0, r = 1;
	int lenMax = 1;
	unordered_set<char> set;
	set.insert(s[0]);

	while (r < s.size())
	{
		if (set.find(s[r]) == set.end())
		{
			lenMax = lenMax >= r - l + 1 ? lenMax : r - l + 1;
			set.insert(s[r]);
			r++;
		}
		else
		{
			while (s[l] != s[r])
			{
				set.erase(s[l]);
				l++;
			}

			set.erase(s[l]);
			l++;
		}
	}

	return lenMax;
}