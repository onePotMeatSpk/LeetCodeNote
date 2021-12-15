#pragma once
#include<queue>
#include<set>
using namespace std;
//题目：地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、
//		右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能
//		够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？



//数位和函数
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

//(x,y)是否可到达
bool isReachable(const int& m, const int& n, const int& k, const set<pair<int, int>>& visited, int x, int y)
{
	//越界
	if ((x < 0) || (x >= n))	return false;
	if ((y < 0) || (y >= m))	return false;
	//已经被占据
	if (visited.find(make_pair(x, y)) != visited.end())	return false;
	//数位和超过k
	if (sumEveryBit(x) + sumEveryBit(y) > k)	return false;
	return true;
}


//DFS解法，时间复杂度O(MN),空间复杂度O(MN)
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



//BFS解法，时间复杂度O(MN),空间复杂度O(MN)
//思路：遍历过程如同层序遍历二叉树，set中有某坐标即表示该坐标已被占据
int movingCountBFS(int m, int n, int k) {
	queue<pair<int, int>> queueNow, queueNext;
	set<pair<int, int>> visited;

	//初始化BFS队列
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
			//提取出当前位置的坐标
			x = queueNow.front().first;
			y = queueNow.front().second;
			//判断当前位置的四个方向是否可到达，如果可到达则入队列并占据
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
			//当前位置遍历完毕
			queueNow.pop();
		}
	}
	
	return visited.size();
}