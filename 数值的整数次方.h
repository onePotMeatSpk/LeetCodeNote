#pragma once
#include<unordered_map>
#include<vector>
using namespace std;
//��Ŀ��ʵ�� pow(x, n) �������� x �� n ���ݺ���������xn��������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

//�����ݣ�������˼ά����������ʱ�临�Ӷ�O(logN)���ռ临�Ӷ�0(1)
//˼·��n���Ա�ת��Ϊ�����ƣ�����������ƣ���ÿһλ��Ϊ0��λ�ϣ�������Ӧ����
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


//�����ݣ����ַ�����ʱ�临�Ӷ�O(logN)���ռ临�Ӷ�O(1)
double myPowRecursion(double x, int n) {

	if (x == 0)	return 0;
	if (n == 0)	return 1;
	if (n == 1)	return x;
	if (n == -1)	return 1 / x;

	//nΪ����
	if (n % 2)
	{
		//nΪ����
		if (n > 0)
			return myPowRecursion(x * x, n / 2) * x;
		//nΪ����
		else
			return myPowRecursion(x * x, n / 2) * (1 / x);
	}
	//nΪż��
	else
	{
		//nΪ����
		if (n > 0)
			return myPowRecursion(x * x, n / 2);
		//nΪ����
		else
			return myPowRecursion(x * x, n / 2);
	}
}