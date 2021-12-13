#pragma once
#include<vector>
#include<string>
using namespace std;
//题目：给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//		单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单
//		元格内的字母不允许被重复使用。

bool isWordExistInBoardCore(vector<vector<char>>& board, string& word, vector<vector<bool>>& boardOccupied, int x, int y, int index) {
	//当前位置已经被占据
	if (boardOccupied[y + 1][x + 1] == true)	return false;
	//当前位置不符合当前检索的字符
	if (word[index] != board[y][x])	return false;
	//当前位置符合当前检索字符，则将当前位置设为已经占据
	boardOccupied[y + 1][x + 1] = true;
	//递归终止条件：word中所有字符检索成功
	if (index == word.size() - 1)	return true;
	//在四个方向检索下一个字符
	if (isWordExistInBoardCore(board, word, boardOccupied, x, y + 1, index + 1) == true)	return true;
	if (isWordExistInBoardCore(board, word, boardOccupied, x, y - 1, index + 1) == true)	return true;
	if (isWordExistInBoardCore(board, word, boardOccupied, x + 1, y, index + 1) == true)	return true;
	if (isWordExistInBoardCore(board, word, boardOccupied, x - 1, y, index + 1) == true)	return true;
	//在四个方向上检索下一个字符都失败，说明当前位置的所有方向不通，释放当前位置，返回上一个位置
	boardOccupied[y + 1][x + 1] = false;
	return false;
}

bool isWordExistInBoard(vector<vector<char>>& board, string word) {
	if (board.size() == 0)	return false;
	if (board[0].size() == 0)	return false;

	//辅助数组中元素为true表示原数组中对应位置已经被占据，辅助数组比原数组多一圈，并且这一圈全部初始化为true
	int raws = board.size(), cols = board[0].size();
	vector<vector<bool>> boardOccupied(raws + 2, vector<bool>(cols + 2, false));
	fill(boardOccupied[0].begin(), boardOccupied[0].end(), true);
	fill(boardOccupied[raws + 1].begin(), boardOccupied[raws + 1].end(), true);
	for (int i = 0; i < raws + 2; i++)
	{
		boardOccupied[i][0] = true;
		boardOccupied[i][cols + 1] = true;
	}

	//以每个位置为起点进行检索
	for (int i = 0; i < raws; i++)
		for (int j = 0; j < cols; j++)
			if (isWordExistInBoardCore(board, word, boardOccupied, j, i, 0))
				return true;
	return false;
}