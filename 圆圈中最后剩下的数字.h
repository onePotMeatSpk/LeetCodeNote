#pragma once
#include<list>
using namespace std;

//！！！复杂度过高的解法：模拟列表，复杂度为O(mn)
//int lastRemaining(int n, int m) {
//
//	//初始化
//	list<int> listNums;
//	for (int i = 0; i < n; i++)
//		listNums.push_back(i);
//	std::list<int>::iterator it = listNums.begin();
//	std::list<int>::iterator itTemp;
//	int index = 1;
//
//	while (listNums.size() > 1) {
//		//如果要删除元素在自index开始的后半段
//		if (listNums.size() - index + 1 >= m)
//		{
//			for (int i = 1; i < m; i++)
//			{
//				it++;
//				index++;
//			}
//
//			//如果删除的是最后一个元素
//			if (index == listNums.size())
//			{
//				index = 1;
//				listNums.pop_back();
//				it = listNums.begin();
//			}
//			else//如果不是最后一个
//			{
//				itTemp = it++;
//				listNums.erase(itTemp);
//			}
//			continue;
//		}
//
//		//如果不在后半段
//		int indexToDel = m - (listNums.size() - index + 1);
//		indexToDel = indexToDel % listNums.size();
//		index = 1;
//		it = listNums.begin();
//		//如果删除的是最后一个元素
//		if (indexToDel == 0)
//		{
//			index = 1;
//			listNums.pop_back();
//			it = listNums.begin();
//		}
//		else//如果不是最后一个
//		{
//			for (int i = 1; i < indexToDel; i++)
//			{
//				it++;
//				index++;
//			}
//			itTemp = it++;
//			listNums.erase(itTemp);
//		}
//	}
//
//	return *it;
//}