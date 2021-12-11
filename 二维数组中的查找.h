#pragma once
#include<vector>
using namespace std;
//��Ŀ����һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ����Ч�ĺ�
//		��������������һ����ά�����һ���������ж��������Ƿ��и�������

//��������ʱ�临�Ӷ�O(N2)���ռ临�Ӷ�O(0)
//bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//	for (int i = 0; i < matrix.size(); i++)
//		for (int j = 0; j < matrix[0].size(); j++)
//			if (target == matrix[i][j])	return true;
//
//	return false;
//}


//�ų�����ʱ�临�Ӷ�O(m+n)��m��nָ������С��У��ռ临�Ӷ�O(0)
//˼�룺�����Ͻ�Ԫ�ؿ�ʼ�������Ե�ǰ����Ԫ��Ϊ�磬�����������Ϊ�����֣���ǰ����Ԫ�ؼ������·�������ͬ�е���ߺ�ͬ�е���
//		�ߣ�����δ���ų����֣����ಿ�־����Ѿ����ų����֣����������ľ���ͨ�������Ͻ�Ԫ�غ�target���бȽϣ��Ӷ��ų�target
//		������λ�ڵĲ��֡�
//		target=���Ͻ�Ԫ�أ��ҵ��ˣ�
//		target>���Ͻ�Ԫ�أ���ǰԪ�������е����ȫ��С�ڵ�ǰԪ�أ���target>��ǰԪ�أ����Ե�ǰ������Ԫ��С��target������
//						   ����ǰ�У�j++��
//		target<���Ͻ�Ԫ�أ���ǰԪ�������е��²�ȫ�����ڵ�ǰԪ�أ���target<��ǰԪ�أ����Ե�ǰ������Ԫ�ش���target������
//						   ����ǰ�У�i--��
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	if (matrix.empty())
		return false;
	if (matrix[0].empty())
		return false;
	int raws = matrix.size(), cols = matrix[0].size();
	int i = cols - 1, j = 0;
	while ((i >= 0) && (j < raws))
	{
		if (matrix[j][i] == target)
			return true;
		else if (matrix[j][i] > target)
			i--;
		else
			j++;
	}

	return false;
}