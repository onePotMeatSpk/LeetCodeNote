#pragma once
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<typeinfo>
#include<stack>
#include<iostream>
#include<queue>
using namespace std;
class Less
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};
class Greater
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void main()
{
    vector<int> v{ 1,5,32,7,3,6,3,7,376,7,3,73,7,3,7,3,73,679,346,569,734545756,789 };
    sort(v.begin(), v.end(), Greater());

   
    for(int i = 0 ; i < v.size();i++)
        cout << v[i] << " ";
    cout << endl;

    priority_queue<int, vector<int>, Greater> pq;
	return;
}
