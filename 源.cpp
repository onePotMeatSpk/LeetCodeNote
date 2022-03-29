#pragma once
#include"includeall.h"

int main()
{
	vector<int> vTree = { 1,2,3,0,0,0,4 };
	vector<int> vToDel = { 2,1 };
	TreeNode* tree = createTree(vTree);

		printTreePreIteration(tree);
		cout << endl;

	vector<TreeNode*> vT = delNodes(tree, vToDel);
	for (int i = 0; i < vT.size(); i++)
	{
		printTreePreIteration(vT[i]);
	cout << endl;
	}

}
