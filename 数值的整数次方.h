#pragma once
#include<unordered_map>
#include<vector>
using namespace std;
//题目：实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

//快速幂（二进制思维，迭代），时间复杂度O(logN)，空间复杂度0(1)
//思路：n可以被转换为二进制，遍历其二进制，在每一位不为0的位上，乘上相应的幂
double myPowIteration(double x, int n) {
	if (x == 0)	return 0;
	if (n == 0)	return 1;

	int tempN = 0;
	double tempX = 0;
	if (n > 0)
	{
		tempN = n;
		tempX = x;
	}
	else
	{
		tempN = -(n + 1);
		tempX = 1 / x;
	}

	double res = 1;
	while (tempN)
	{
		if (tempN & 1)
			res *= tempX;
		tempX *= tempX;
		tempN >>= 1;
	}

	if (n < 0)
		res *= (1 / x);
	return res;
}


//快速幂（二分法），时间复杂度O(logN)，空间复杂度O(1)
double myPowRecursion(double x, int n) {

	if (x == 0)	return 0;
	if (n == 0)	return 1;
	if (n == 1)	return x;
	if (n == -1)	return 1 / x;

	//n为奇数
	if (n % 2)
	{
		//n为正数
		if (n > 0)
			return myPowRecursion(x * x, n / 2) * x;
		//n为负数
		else
			return myPowRecursion(x * x, n / 2) * (1 / x);
	}
	//n为偶数
	else
	{
		//n为正数
		if (n > 0)
			return myPowRecursion(x * x, n / 2);
		//n为负数
		else
			return myPowRecursion(x * x, n / 2);
	}
}