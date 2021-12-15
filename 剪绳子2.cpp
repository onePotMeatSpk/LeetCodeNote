using namespace std;
//题目：长度为 n 的绳子，把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1]。
//		请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，\
//		此时得到的最大乘积是18。
//		答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。

//！！！求余函数的返回必须是long，因为最后返回值mode1000000007之前很可能超过int
//快速幂求余，时间复杂度O(logN)
 long quickPowerMode(int x)
{
	if (x == 0)	return 1;
	if (x == 1)	return 3;
	return	quickPowerMode(x / 2) * quickPowerMode(x - x / 2) % 1000000007;
}

//迭代乘求余，时间复杂度为O(N)
long iterationTimesMode(int x)
{
	if (x == 0)	return 0;
	if (x == 1)	return 3;
	return iterationTimesMode(x - 1) * 3 % 1000000007;
}


//贪心算法：这道题不可再用剪绳子中的动态规划，因为这里每一步都需要求余，最大值求余之后可能会变小，导致动态规划中的最大值
//			无法更新
//			迭代乘求余时，时间复杂度O(1*N)=O(N)，空间复杂度O(1)
//			迭代乘求余时，时间复杂度O(1*logN)=O(logN)，空间复杂度O(1)
int cuttingRope2(int n) {
	if (n == 0)	return 0;
	if (n < 3)	return 1;
	if (n == 3)	return 2;

	int a = n / 3;
	int b = n % 3;
	if (b == 0)	return	quickPowerMode(a);
	if (b == 1)	return (quickPowerMode(a - 1) * 4) % 1000000007;
	if (b == 2)	return	(quickPowerMode(a) * 2) % 1000000007;
	return 0;
}