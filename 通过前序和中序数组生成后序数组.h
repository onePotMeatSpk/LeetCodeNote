#pragma once
#include<vector>
using namespace std;

void getPosArrayWithPreAndInCore(const vector<int>& preArray, int preL, int preR,
								 const vector<int>& inArray, int inL, int inR,
								 vector<int>& posArray, int posL, int posR) {
	//防止索引越界
	if ((preL < 0) || (inL < 0) || (posL < 0) || (preR >= preArray.size()) || (inR >= preArray.size()) || (posR >= preArray.size()))	return;
	//递归终止
	if (preR < preL)	return;
	//确定根节点
	posArray[posR] = preArray[preL];
	//计算左右子树范围
	int mid = 0;
	for (int i = inL; i <= inR; i++)
	{
		if (inArray[i] == preArray[preL])
		{
			mid = i;
			break;
		}
	}
	int rangeL = mid - inL - 1;
	int rangeR = inR - mid - 1;
	
	//分别对左子树和右子树的数组进行构造
	getPosArrayWithPreAndInCore(preArray, preL + 1, preL + 1 + rangeL, inArray, inL, mid - 1, posArray, posL, posL + rangeL);
	getPosArrayWithPreAndInCore(preArray, preR - rangeR, preR, inArray, mid + 1, inR, posArray, posR - 1 - rangeR, posR - 1);
}

vector<int> getPosArrayWithPreAndIn(const vector<int>& preArray, const vector<int>& inArray) {
	int len = preArray.size();
	vector<int> posArray;
	posArray.resize(len);
	getPosArrayWithPreAndInCore(preArray, 0, len - 1, inArray, 0, len - 1, posArray, 0, len - 1);
	return posArray;
}