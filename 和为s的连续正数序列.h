#pragma once
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
	vector<int>vectorOfGroup;
	vector<vector<int>>vectorOfGroups;
	if (target < 3)	return vectorOfGroups;
	int i = 1, j = 2, sum = 3;
	while (i < j)
	{
		if (sum == target)
		{
			vectorOfGroup.clear();
			for (int index = i; index <= j; index++)
				vectorOfGroup.push_back(index);
			vectorOfGroups.push_back(vectorOfGroup);
			j++;
			sum += j;
		}
		else if (sum < target)
		{
			j++;
			sum += j;
		}
		else
		{
			sum -= i;
			i++;
		}
	}

	return vectorOfGroups;
}