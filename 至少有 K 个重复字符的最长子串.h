#pragma once
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//力扣395
//至少有 K 个重复字符的最长子串
//给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。


//分治法：
	//任何字符串中，只要包含了数量不足k的字母，就不符合题目要求
	//所以，使用数量不足k的字母，将字符串分割为子串，再看各个子串是否符合题目要求（分治）
int split(string& s, int& k, int l, int r)
{
	//[l, r]子串长度小于k，则肯定不符合题目要求
	if (r - l + 1 < k)	return 0;

	unordered_map<char, int> map;
	unordered_set<char> set;

	//统计[l, r]子串中，各字母数量
	for (int i = l; i <= r; i++)
		map[s[i]]++;

	//找出[l, r]子串中，数量不足k的字母
	for (auto it = map.begin(); it != map.end(); it++)
		if (it->second < k)	set.insert(it->first);

	//[l, r]子串中，没有数量不足k的字母，则[l,r]子串符合要求
	if (set.empty())	return r - l + 1;

	//统计[l, r]子串中，数量不足k的字母的坐标
	vector<int> vec;
	for (int i = l; i <= r; i++)
		if (set.find(s[i]) != set.end())	vec.push_back(i);

	//任何字符串中，只要包含了数量不足k的字母，就不符合题目要求
	//所以，使用数量不足k的字母，将字符串分割为子串，再看各个子串是否符合题目要求
	int lenMax = 0, len;
	int right, left;
	//前面几个子串
	for (int i = 0; i < vec.size(); i++)
	{
		left = i == 0 ? l : vec[i - 1] + 1;
		right = vec[i] - 1;
		len = split(s, k, left, right);
		lenMax = lenMax >= len ? lenMax : len;
	}
	//最后一个子串
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