#pragma once
#include<vector>
using namespace std;
/*
* 数组中数字出现的次数有两种情况
* 第一种：数组中仅有1个只出现1次的数字，其他数字均出现2次
* 第二种：数组中有2个只出现1次的数字，其他数字均出现2次
* 第三种：数组中仅有1个只出现1次的数字，其他数字均出现3次
*/


//第二种：数组中有2个只出现1次的数字，其他数字均出现2次
//核心思想：相同数字异或为0，0与任何其他数字异或仍为0，异或遵循交换律。
//			则两数字按位异或（^运算符）得到数字的各二进制位的值可表示两数字各二进制位的异同，在某二进制
//			位两者相同则该位为0，不相同则该位为1。比如，A=1（001），B=4（100），则A^B=5（101）。
vector<int> singleNumbers(vector<int>& nums)
{
	vector<int> vectorOfSingleNumbers;

	if (nums.empty())	return vectorOfSingleNumbers;
	if (nums.size() < 4)	return vectorOfSingleNumbers;

	//第一步：确定不重复两数字的异或
	//实现思想：将数组中数字分为几类：不重复数字A、B；第一队重复数字R11、R12；第二队重复数字R21、R22；…；第n对重复数字
	//			Rn1、Rn2。
	//			设所有数字的异或结果为 Z = A xor B xor R11 xor R12 xor R21 xor R22 xor … xor Rn1 xor Rn2。
	//			因为相等数字异或结果为0，且异或遵从交换律，所以 Z = A xor B xor 0 xor 0 xor … xor 0。因为0与任何数字的
	//			异或结果为0，所以Z = A xor B。
	int z = 0;
	for (int i = 0; i < nums.size(); i++)//将nums中的数字全部异或起来得到不重复数字的异或
		z ^= nums[i];

	
	//第二步：找不重复两数字的不同之处
	//实现思想：A、B不相等，则其二进制表达至少有一位不相等，在某一不等位上A为0，B为1。从低位到高位，对每一位进行对照，即
	//			可知道哪一位不相等。
	//每一位对照的方法：举个例子来说明：A = 4（100），B = 2（010）。设maskDifference = 1（001）来表示A与B不同的第一个位，
	//			可以看到maskDifference除了最低位为1，其余为均为0，那么如果数字C的最低位为0，则C & maskDifference = 0（因
	//			为maskDifference的其他位均为0，所以不管C的其他位是什么，按位与结果的其他位均为0），同理如果C的最低位为1，
	//			则C & maskDifference = 1。
	//进位方法：如果A、B在某一位相等，就需要进一步到高位进行检查，进位的方法是将maskDifference左移一位（或者乘2），比如1
	//			（001）左移一位变成了2（010），010的第二位为1、其余位为0，可用于检查第二位是否不等。
	int maskDifference = 1;
	for (int i = 0; i < 31; i++)
	{
		if ((z & maskDifference) != 0)	break;
		maskDifference <<= 1;
	}

	//第三步：将A、B分开
	//实现思想：可将数字分为两类，一类为与A相似类（它们与maskDifference按位与的结果是0），另一类为与B相似类（结果非0），
	//			然后两类分别异或，相同的数字异或得到的结果为0，最终留下来的便是A、B。
	int x = 0, y = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if ((nums[i] & maskDifference) == 0)	x ^= nums[i];
		else
			y ^= nums[i];
	}

	vectorOfSingleNumbers.push_back(x);
	vectorOfSingleNumbers.push_back(y);
	return vectorOfSingleNumbers;
}

//第三种：数组中仅有1个只出现1次的数字，其他数字均出现3次
int singleNumber(vector<int>& nums)
{
	if (nums.empty())	return 0;
	if (nums.size() < 4)	return 0;

	int counterOfBits[32];
	memset(counterOfBits, 0, 32 * 4);
	int maskBit = 1;
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < nums.size(); j++)
			if ((nums[j] & maskBit) != 0)	counterOfBits[i]++;
		if(i<31)	maskBit <<= 1;
	}

	for (int i = 0; i < 32; i++)
		counterOfBits[i] %= 3;

	int result = 0;
	for (int i = 0; i < 32; i++)
		if(counterOfBits[i] != 0)	result += (pow(2, i));

	return result;
}