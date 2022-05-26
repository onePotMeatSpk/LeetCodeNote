#pragma once
#include"二叉树.h"
#include<unordered_map>

//力扣437
//题目：二叉树路径总和III_不要求过根节点
//题目描述：给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
//路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。


//解题思路：哈希map存储到达当前节点所经过的所有节点的各自前缀和，sum存储当前前缀和已经到达多少了，
//若本节点的前缀和为a，则前缀和为a-target的节点，从该节点（不包含该节点）到本节点的路经长就是target

//方法1：递归
int pathSumCore(TreeNode* root, const int& targetSum, unordered_map<int, int>& m, int sum = 0)
{
    if (!root)   return 0;
    sum += root->val;
    //判断到达当前节点路径和为target的节点
    int count = m[sum - targetSum];
    m[sum]++;

    //递归下面的节点
    count += pathSumCore(root->left, targetSum, m, sum);
    count += pathSumCore(root->right, targetSum, m, sum);

    //将当前节点从路径中擦除
    m[sum]--;
    return count;
}

int pathSum(TreeNode* root, int targetSum) {
    unordered_map<int, int> m;
    m[0] = 1;//根节点之前也应该初始化一个0前缀和，因为有些路径是从根节点（包含根节点）开始的
    return pathSumCore(root, targetSum, m);
}

//方法2：迭代
int pathSum(TreeNode* root, int targetSum) {
    if (!root)   return 0;

    unordered_map<int, int> map;
    map[0] = 1;
    stack<TreeNode*> s;
    s.push(root);
    int ret = 0, sum = 0;

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();
            s.push(temp);
            s.push(NULL);
            sum += temp->val;
            ret += map[sum - targetSum];
            map[sum]++;

            if (temp->left)  s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            map[sum]--;
            sum -= temp->val;
        }
    }

    return ret;
}
