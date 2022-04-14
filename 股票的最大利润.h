#pragma once
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
	int numDays = prices.size();
	//Â³°ô
	if (numDays < 2)	return 0;

	vector<int> dp(numDays, 0);
	dp[0] = 0;
	int lowestPrice = prices[0];
	for (int i = 1; i < numDays; i++)
	{
		dp[i] = max(dp[i - 1], prices[i] - lowestPrice);
		lowestPrice = lowestPrice < prices[i] ? lowestPrice : prices[i];
	}
	return dp[numDays - 1];
}