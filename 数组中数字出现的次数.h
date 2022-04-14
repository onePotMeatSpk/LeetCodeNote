#pragma once
#include<vector>
using namespace std;
/*
* ���������ֳ��ֵĴ������������
* ��һ�֣������н���1��ֻ����1�ε����֣��������־�����2��
* �ڶ��֣���������2��ֻ����1�ε����֣��������־�����2��
* �����֣������н���1��ֻ����1�ε����֣��������־�����3��
*/


//�ڶ��֣���������2��ֻ����1�ε����֣��������־�����2��
//����˼�룺��ͬ�������Ϊ0��0���κ��������������Ϊ0�������ѭ�����ɡ�
//			�������ְ�λ���^��������õ����ֵĸ�������λ��ֵ�ɱ�ʾ�����ָ�������λ����ͬ����ĳ������
//			λ������ͬ���λΪ0������ͬ���λΪ1�����磬A=1��001����B=4��100������A^B=5��101����
vector<int> singleNumbers(vector<int>& nums)
{
	vector<int> vectorOfSingleNumbers;

	if (nums.empty())	return vectorOfSingleNumbers;
	if (nums.size() < 4)	return vectorOfSingleNumbers;

	//��һ����ȷ�����ظ������ֵ����
	//ʵ��˼�룺�����������ַ�Ϊ���ࣺ���ظ�����A��B����һ���ظ�����R11��R12���ڶ����ظ�����R21��R22��������n���ظ�����
	//			Rn1��Rn2��
	//			���������ֵ������Ϊ Z = A xor B xor R11 xor R12 xor R21 xor R22 xor �� xor Rn1 xor Rn2��
	//			��Ϊ������������Ϊ0���������ӽ����ɣ����� Z = A xor B xor 0 xor 0 xor �� xor 0����Ϊ0���κ����ֵ�
	//			�����Ϊ0������Z = A xor B��
	int z = 0;
	for (int i = 0; i < nums.size(); i++)//��nums�е�����ȫ����������õ����ظ����ֵ����
		z ^= nums[i];

	
	//�ڶ������Ҳ��ظ������ֵĲ�֮ͬ��
	//ʵ��˼�룺A��B����ȣ���������Ʊ��������һλ����ȣ���ĳһ����λ��AΪ0��BΪ1���ӵ�λ����λ����ÿһλ���ж��գ���
	//			��֪����һλ����ȡ�
	//ÿһλ���յķ������ٸ�������˵����A = 4��100����B = 2��010������maskDifference = 1��001������ʾA��B��ͬ�ĵ�һ��λ��
	//			���Կ���maskDifference�������λΪ1������Ϊ��Ϊ0����ô�������C�����λΪ0����C & maskDifference = 0����
	//			ΪmaskDifference������λ��Ϊ0�����Բ���C������λ��ʲô����λ����������λ��Ϊ0����ͬ�����C�����λΪ1��
	//			��C & maskDifference = 1��
	//��λ���������A��B��ĳһλ��ȣ�����Ҫ��һ������λ���м�飬��λ�ķ����ǽ�maskDifference����һλ�����߳�2��������1
	//			��001������һλ�����2��010����010�ĵڶ�λΪ1������λΪ0�������ڼ��ڶ�λ�Ƿ񲻵ȡ�
	int maskDifference = 1;
	for (int i = 0; i < 31; i++)
	{
		if ((z & maskDifference) != 0)	break;
		maskDifference <<= 1;
	}

	//����������A��B�ֿ�
	//ʵ��˼�룺�ɽ����ַ�Ϊ���࣬һ��Ϊ��A�����ࣨ������maskDifference��λ��Ľ����0������һ��Ϊ��B�����ࣨ�����0����
	//			Ȼ������ֱ������ͬ���������õ��Ľ��Ϊ0�������������ı���A��B��
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

//�����֣������н���1��ֻ����1�ε����֣��������־�����3��
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