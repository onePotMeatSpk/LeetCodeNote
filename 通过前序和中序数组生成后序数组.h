#pragma once
#include<vector>
using namespace std;

void getPosArrayWithPreAndInCore(const vector<int>& preArray, int preL, int preR,
								 const vector<int>& inArray, int inL, int inR,
								 vector<int>& posArray, int posL, int posR) {
	//��ֹ����Խ��
	if ((preL < 0) || (inL < 0) || (posL < 0) || (preR >= preArray.size()) || (inR >= preArray.size()) || (posR >= preArray.size()))	return;
	//�ݹ���ֹ
	if (preR < preL)	return;
	//ȷ�����ڵ�
	posArray[posR] = preArray[preL];
	//��������������Χ
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
	
	//�ֱ������������������������й���
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