#pragma once
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0)	return -1;
	if (len == 1)	return 0;

	vector<int> dpOfFront(len);
	vector<int> dpOfBehind(len);

	dpOfFront[0] = 0;
	dpOfBehind[0] = 0;
	for (int i = 1; i < len; i++)
		dpOfBehind[0] += nums[i];

	if (dpOfFront[0] == dpOfBehind[0])	return 0;

	for (int i = 1; i < len; i++)
	{
		dpOfFront[i] = dpOfFront[i - 1] + nums[i - 1];
		dpOfBehind[i] = dpOfBehind[i - 1] - nums[i];
		if (dpOfFront[i] == dpOfBehind[i])	return i;
	}
	return -1;
}