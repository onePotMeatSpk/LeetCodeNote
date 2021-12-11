#pragma once
#include<vector>
using namespace std;
//题目：在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函
//		数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

//暴力法，时间复杂度O(N2)，空间复杂度O(0)
//bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//	for (int i = 0; i < matrix.size(); i++)
//		for (int j = 0; j < matrix[0].size(); j++)
//			if (target == matrix[i][j])	return true;
//
//	return false;
//}


//排除法，时间复杂度O(m+n)，m、n指矩阵的行、列，空间复杂度O(0)
//思想：从右上角元素开始遍历，以当前遍历元素为界，将整个矩阵分为两部分，当前遍历元素及其左下方（包括同行的左边和同列的下
//		边）就是未被排除部分，其余部分就是已经被排除部分，我们所做的就是通过将右上角元素和target进行比较，从而排除target
//		不可能位于的部分。
//		target=右上角元素：找到了；
//		target>右上角元素：当前元素所在行的左侧全部小于当前元素，且target>当前元素，所以当前行所有元素小于target，故排
//						   除当前行，j++；
//		target<右上角元素：当前元素所在列的下侧全部大于当前元素，且target<当前元素，所以当前列所有元素大于target，故排
//						   除当前列，i--；
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