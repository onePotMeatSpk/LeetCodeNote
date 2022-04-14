#pragma once
#include<stack>
#include<string>
using namespace std;

string reverseWords(string s)
{
	string stringBuffer;
	stack<string>stackBuffer;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			stringBuffer += s[i];
			if (i == s.size() - 1)
			{
				stackBuffer.push(stringBuffer);
				stringBuffer.clear();
			}
			continue;
		}
			
		if (stringBuffer.size())
		{
			stackBuffer.push(stringBuffer);
			stringBuffer.clear();
		}
	}

	while (stackBuffer.size())
	{
		stringBuffer += stackBuffer.top();
		stringBuffer += ' ';
		stackBuffer.pop();
	}
	stringBuffer.pop_back();
	return stringBuffer;
}