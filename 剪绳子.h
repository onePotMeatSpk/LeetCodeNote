#pragma once
#include<vector>
using namespace std;
//题目：一根长为 n 的绳子，把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1]。
//		请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
//		时得到的最大乘积是18。

//动态规划，时间复杂度O(N2)，空间复杂度O(N)
int cuttingRope(int n) {
	if (n == 0)	return 0;
	vector<int> f(n + 1);
	f[0] = 1;
	f[1] = 1;
	int maxAll = 1, maxNow = 0;
	
	for (int i = 2; i <= n; i++)
	{
		maxNow = 0;
		for (int j = 1; j <= i / 2; j++)
			maxNow = max(i - j, f[i - j]) * max(j, f[j]) > maxNow ? max(i - j, f[i - j]) * max(j, f[j]) : maxNow;
		//转移方程解释：将绳子剪为两段（保证m>1），这两段可以选择继续向下剪或者不剪，让总乘积最大的方法就是分别让两段各自
		//				的乘积最大，两子段分别在剪或不剪中选择最大的即可。
		f[i] = maxNow;
		maxAll = f[i] > maxAll ? f[i] : maxAll;
	}

	return maxAll;
}