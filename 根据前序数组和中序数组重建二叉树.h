#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>
#include"二叉树.h"
using namespace std;

//时间复杂度为O(NlogN)。创建各节点为O(N)，在各节点中查找根节点平均为O(logN)。总复杂度=O(N)*O(logN)=O(NlogN)
// 解题思路，前序数组首元素为根节点，根据这个元素在中序数组中找到根节点的位置，中序数组中，在根节点之前的即为左子树，之后
// 的即为右子树。依次递归。
// 注意：区间为前闭后闭
//TreeNode* rebuildTreeWithPreAndInCore(vector<int>& vPre, vector<int>& vIn, int startPre, int endPre, int startIn, int endIn) {
//    if (startPre > endPre)   return NULL;
//    TreeNode* root = new TreeNode(vPre[startPre]);
//
//    int leftLen = 0;
//    for (int i = startIn; i <= endIn; i++)
//    {
//        if (vIn[i] != vPre[startPre])    leftLen++;
//        else                            break;
//    }
//    root->left = rebuildTreeWithPreAndInCore(vPre, vIn, startPre + 1, startPre + leftLen, startIn, startIn + leftLen - 1);
//    root->right = rebuildTreeWithPreAndInCore(vPre, vIn, startPre + leftLen + 1, endPre, startIn + leftLen + 1, endIn);
//
//    return root;
//}
//
//
//TreeNode* rebuildTreeWithPreAndIn(vector<int>& preorder, vector<int>& inorder) {
//	return rebuildTreeWithPreAndInCore(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
//}


//时间复杂度为O(N)。与上面相比，该解将查找根节点复杂度变为O(1)，做法是在重建二叉树之前，将中序数组按照<元素值，下标>的
// 对应关系提前放到了哈希表中，这个过程的时间复杂度为O(N)。总复杂度=O(N)+O(N)*O(1)=O(N)
//解题思路：与上面这个解思路一样。
TreeNode* rebuildTreeWithPreAndInCore(vector<int>& vPre, vector<int>& vIn, unordered_map<int,int>& map, int startPre, int endPre, int startIn, int endIn) {
    if (startPre > endPre)   return NULL;
    TreeNode* root = new TreeNode(vPre[startPre]);

    int leftLen = map[vPre[startPre]] - startIn;
    root->left = rebuildTreeWithPreAndInCore(vPre, vIn, map, startPre + 1, startPre + leftLen, startIn, startIn + leftLen - 1);
    root->right = rebuildTreeWithPreAndInCore(vPre, vIn, map, startPre + leftLen + 1, endPre, startIn + leftLen + 1, endIn);

    return root;
}


TreeNode* rebuildTreeWithPreAndIn(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i;
	return rebuildTreeWithPreAndInCore(preorder, inorder, map, 0, preorder.size() - 1, 0, inorder.size() - 1);
}
