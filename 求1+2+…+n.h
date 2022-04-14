#pragma once
using namespace std;
int sum = 0;
int sumNums(int n) {
	//&&以及||都可以，这里利用了两者的短路特性
	//n > 1 && sumNums(n - 1);
	(n == 1) || sumNums(n - 1);
	sum += n;
	return sum;
}