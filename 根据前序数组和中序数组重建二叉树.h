#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>
#include"������.h"
using namespace std;

//ʱ�临�Ӷ�ΪO(NlogN)���������ڵ�ΪO(N)���ڸ��ڵ��в��Ҹ��ڵ�ƽ��ΪO(logN)���ܸ��Ӷ�=O(N)*O(logN)=O(NlogN)
// ����˼·��ǰ��������Ԫ��Ϊ���ڵ㣬�������Ԫ���������������ҵ����ڵ��λ�ã����������У��ڸ��ڵ�֮ǰ�ļ�Ϊ��������֮��
// �ļ�Ϊ�����������εݹ顣
// ע�⣺����Ϊǰ�պ��
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


//ʱ�临�Ӷ�ΪO(N)����������ȣ��ý⽫���Ҹ��ڵ㸴�Ӷȱ�ΪO(1)�����������ؽ�������֮ǰ�����������鰴��<Ԫ��ֵ���±�>��
// ��Ӧ��ϵ��ǰ�ŵ��˹�ϣ���У�������̵�ʱ�临�Ӷ�ΪO(N)���ܸ��Ӷ�=O(N)+O(N)*O(1)=O(N)
//����˼·�������������˼·һ����
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
