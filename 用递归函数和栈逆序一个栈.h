#pragma once
#include<stack>
#include<iostream>
using namespace std;

int getAndPopLastEle(stack<int>& s)
{
	int tempTop = s.top();
	s.pop();
	if (s.empty())	return tempTop;
	int tempLast = getAndPopLastEle(s);
	s.push(tempTop);
	return tempLast;
}

void reverse(stack<int>& s) {
	if (s.empty())	return;
	int temp = getAndPopLastEle(s);
	reverse(s);
	s.push(temp);
}