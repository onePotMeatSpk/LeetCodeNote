#pragma once
#include<vector>
using namespace std;

bool verifyPostorderCore(vector<int>& postorder, int l, int r) {
    //仅有根
    if (l == r) return true;
    //找到第一个比根小的数字，索引设为mid
    int mid = r - 1;
    while ((mid >= l) && (postorder[mid] > postorder[r]))
        --mid;

    //无比根小的数字，当前范围内除了根就是右子树
    if (mid < l)    return verifyPostorderCore(postorder, l, r - 1);

    //检查mid前是否仍然存在比根大的数字，若有的话说明根的左子树是不成立的
    for (int i = mid - 1; i >= l; i--)
        if (postorder[i] > postorder[r])    return false;

    //无比根大的数字，当前范围内除了根就是左子树
    if (mid == r - 1)    return verifyPostorderCore(postorder, l, r - 1);

    //左右子树均有，递归下去判断左右子树是否均成立
    return (verifyPostorderCore(postorder, l, mid) && verifyPostorderCore(postorder, mid + 1, r - 1));
}

bool verifyPostorder(vector<int>& postorder) {
    if (postorder.size() == 0)   return true;
    if (verifyPostorderCore(postorder, 0, postorder.size() - 1))  return true;
    else    return false;
}