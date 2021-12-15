#pragma once
#include<queue>
#include<set>
using namespace std;
//��Ŀ��������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο�������
//		�ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ18ʱ����������
//		�����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�



//��λ�ͺ���
int sumEveryBit(int x)
{
	int sum = 0;
	while (x)
	{
		sum += (x % 10);
		x /= 10;
	}
	return sum;
}

//(x,y)�Ƿ�ɵ���
bool isReachable(const int& m, const int& n, const int& k, const set<pair<int, int>>& visited, int x, int y)
{
	//Խ��
	if ((x < 0) || (x >= n))	return false;
	if ((y < 0) || (y >= m))	return false;
	//�Ѿ���ռ��
	if (visited.find(make_pair(x, y)) != visited.end())	return false;
	//��λ�ͳ���k
	if (sumEveryBit(x) + sumEveryBit(y) > k)	return false;
	return true;
}


//DFS�ⷨ��ʱ�临�Ӷ�O(MN),�ռ临�Ӷ�O(MN)
int movingCountDFSCore(const int& m, const int& n, const int& k, set<pair<int, int>>& visited, int x, int y)
{
	if (isReachable(m, n, k, visited, x, y) == false)	return 0;
	visited.insert(make_pair(x, y));
	return movingCountDFSCore(m, n, k, visited, x + 1, y)
		+ movingCountDFSCore(m, n, k, visited, x - 1, y)
		+ movingCountDFSCore(m, n, k, visited, x, y + 1)
		+ movingCountDFSCore(m, n, k, visited, x, y - 1)
		+1;
}
int movingCountDFS(int m, int n, int k) {
	set<pair<int, int>> visited;
	return movingCountDFSCore(m, n, k, visited, 0, 0);
}



//BFS�ⷨ��ʱ�临�Ӷ�O(MN),�ռ临�Ӷ�O(MN)
//˼·������������ͬ���������������set����ĳ���꼴��ʾ�������ѱ�ռ��
int movingCountBFS(int m, int n, int k) {
	queue<pair<int, int>> queueNow, queueNext;
	set<pair<int, int>> visited;

	//��ʼ��BFS����
	queueNext.push(make_pair(0, 0));
	visited.insert(make_pair(0, 0));
	int x, y;

	//BFS
	while (!queueNext.empty())
	{
		queueNow = queueNext;
		while (!queueNext.empty())
			queueNext.pop();

		while (!queueNow.empty())
		{
			//��ȡ����ǰλ�õ�����
			x = queueNow.front().first;
			y = queueNow.front().second;
			//�жϵ�ǰλ�õ��ĸ������Ƿ�ɵ������ɵ���������в�ռ��
			if (isReachable(m, n, k, visited, x - 1, y)){
				queueNext.push(make_pair(x - 1, y));
				visited.insert(make_pair(x - 1, y));
			}
			if (isReachable(m, n, k, visited, x + 1, y)){
				queueNext.push(make_pair(x + 1, y));
				visited.insert(make_pair(x + 1, y));
			}
			if (isReachable(m, n, k, visited, x, y - 1)){
				queueNext.push(make_pair(x, y - 1));
				visited.insert(make_pair(x, y - 1));
			}
			if (isReachable(m, n, k, visited, x, y + 1)){
				queueNext.push(make_pair(x, y + 1));
				visited.insert(make_pair(x, y + 1));
			}
			//��ǰλ�ñ������
			queueNow.pop();
		}
	}
	
	return visited.size();
}