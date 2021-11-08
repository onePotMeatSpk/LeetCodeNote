#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseLeftWords(string s, int n)
{
	if (n <= 0)	return s;
	if (n >= s.size())	return s;
	string sNew;
	for (int i = n; i < s.size(); i++)
		sNew += s[i];
	for (int i = 0; i < n; i++)
		sNew += s[i];
	return sNew;
}