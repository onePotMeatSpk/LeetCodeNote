#pragma once
#include"二叉树.h"
using namespace std;

//力扣124
//题目：二叉树最大路径和
//题目描述：路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
//			路径和 是路径中各节点值的总和。
//			给你一个二叉树的根节点 root ，返回其 最大路径和 。

//思路：类似二叉树的直径
//
struct Res {
    int sumForIn;//内向路径：某树内的最大路径和
    int sumForOut;//外向路径：某树内的，终点为根节点的路径的路径和，用来向该树外延伸以探索更长的路径
    Res() : sumForIn(-9999), sumForOut(-9999) {};//-9999，是因为力扣124中节点最小为-1000
};

struct Res dfsMaxPathSum(TreeNode* root) {
    Res res;
    //到达NULL，递归终止
    if (!root)   return res;
    //收集左右子树信息
    Res resL = dfsMaxPathSum(root->left);
    Res resR = dfsMaxPathSum(root->right);

    //信息汇总
    // 
    //本树外向路径，有两种可能：起点来自子树、起点是根节点，取两者最大者即可
    //起点来自子树：有可能来自左子树、右子树，取两者最大值即可
    //起点是根节点：直接取根节点值即可
    res.sumForOut = max(max(resL.sumForOut, resR.sumForOut), 0) + root->val;

    //本树内向路径，有两种可能：经过、不经过root，取两者最大者即可
    //经过root：几种可能：左根右、左根、根右、根，取其中最大值即可，其中左右都是取左右子树的外向路径
    //不经过root：取左右子树的内向路径中的最大者
    res.sumForIn = max(max(max(resL.sumForIn, resR.sumForIn), max(resL.sumForOut, resR.sumForOut) + root->val),
        max(resL.sumForOut + resR.sumForOut + root->val, root->val));
    return res;
}

int maxPathSum(TreeNode* root) {
    if (!root)   return 0;
    Res res = dfsMaxPathSum(root);
    return res.sumForIn;
}
