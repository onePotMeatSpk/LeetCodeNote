#pragma once
#include<list>
using namespace std;

//���������Ӷȹ��ߵĽⷨ��ģ���б����Ӷ�ΪO(mn)
//int lastRemaining(int n, int m) {
//
//	//��ʼ��
//	list<int> listNums;
//	for (int i = 0; i < n; i++)
//		listNums.push_back(i);
//	std::list<int>::iterator it = listNums.begin();
//	std::list<int>::iterator itTemp;
//	int index = 1;
//
//	while (listNums.size() > 1) {
//		//���Ҫɾ��Ԫ������index��ʼ�ĺ���
//		if (listNums.size() - index + 1 >= m)
//		{
//			for (int i = 1; i < m; i++)
//			{
//				it++;
//				index++;
//			}
//
//			//���ɾ���������һ��Ԫ��
//			if (index == listNums.size())
//			{
//				index = 1;
//				listNums.pop_back();
//				it = listNums.begin();
//			}
//			else//����������һ��
//			{
//				itTemp = it++;
//				listNums.erase(itTemp);
//			}
//			continue;
//		}
//
//		//������ں���
//		int indexToDel = m - (listNums.size() - index + 1);
//		indexToDel = indexToDel % listNums.size();
//		index = 1;
//		it = listNums.begin();
//		//���ɾ���������һ��Ԫ��
//		if (indexToDel == 0)
//		{
//			index = 1;
//			listNums.pop_back();
//			it = listNums.begin();
//		}
//		else//����������һ��
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