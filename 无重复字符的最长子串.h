#pragma once
#include<string>
#include<unordered_set>
using namespace std;
//力扣3
//无重复字符的最长子串
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

//思路：滑动窗口
	//什么是滑动窗口？
	//其实就是一个队列, 比如例题中的 abcabcbb，进入这个队列（窗口）为 abc 满足题目要求，当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！
	//如何移动？
	//我们只要把队列的左边的元素移出就行了，直到满足题目要求！
	//一直维持这样的队列，找出队列出现最长的长度时候，求出解
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