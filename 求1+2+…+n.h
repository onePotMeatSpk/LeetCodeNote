#pragma once
using namespace std;
int sum = 0;
int sumNums(int n) {
	//&&�Լ�||�����ԣ��������������ߵĶ�·����
	//n > 1 && sumNums(n - 1);
	(n == 1) || sumNums(n - 1);
	sum += n;
	return sum;
}