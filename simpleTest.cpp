#pragma once
#include<iostream>
#include<string>

#include<queue>
#include"数据流中的中位数.h"
using namespace std;

struct S
{
	int i;
	S(int _i) :i(_i)
	{

	}

	bool operator<(const S& s1)	const
	{
		return i < s1.i;
	}

	bool operator>(const S& s1)	const
	{
		return i > s1.i;
	}

	bool operator==(const S& s1)	const
	{
		return i == s1.i;
	}
};


void main()
{
	priority_queue<S, vector<S>, less<S>> p1;

	priority_queue<S, vector<S>, greater<S>> p2;

	for (int i = 0; i < 5; i++)
	{
		p1.push(S(i));
		p2.push(S(i));
	}


	for (int i = 0; i < 5; i++)
	{
		cout << p1.top().i << " ";
		p1.pop();
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << p2.top().i << " ";
		p2.pop();
	}
	cout << endl;


	return;

}