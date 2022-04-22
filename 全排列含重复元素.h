#pragma once
#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//题目：全排列含重复元素
//题目描述：给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

//dfs函数
void dfsPermuteUnique(vector<vector<int>>& vAll, vector<int>& nums, vector<bool>& visit, vector<int>& v, int index)
{
    if (index == nums.size())
    {
        vAll.push_back(v);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {

        //其余为全排列基操，除了两行，此处为其中一行
        //有两元素：i&&nums[i] == nums[i - 1]、!visit[i - 1]，以&&连
        //i&&nums[i] == nums[i - 1]：i-1与i相等，说明i为重复元素，有可能导致重复排列，需要特别处理
        //!visit[i - 1]：在i与i-1相等的情况下：1)如果i-1没有被占据，那么当前位不可以用i，因为必定会导致重复排列；2)否则，可以用i，因为不会导致重复排列
        //  以{1,1,1,2}为例
        //  1)如果首位用第一个1，第二位用第二个1，则不会造成重复。因为第二个1前方的1被占，则肯定是高位占的，也就是说当前1是当前位碰到的第一个，当然可以直接用。
        //  2)如果首位用第一个1，第二位用第三个1，则会造成重复。因为第三个1前方的1未占，则说明当前位在上一个全排列中，曾经使用过前方1，因为for循环，所以前方1才空出来。
        if (i && nums[i] == nums[i - 1] && !visit[i - 1]) continue;

        if (visit[i])    continue;
        visit[i] = 1;
        v.push_back(nums[i]);
        dfsPermuteUnique(vAll, nums, visit, v, index + 1);
        visit[i] = 0;
        v.pop_back();
    }
}

//主函数
vector<vector<int>> permuteUnique(vector<int>& nums) {
    //其余为全排列基操，除了两行，此处为其中一行
    //重复的数字如果散落在各处的话，很难对重复与否进行判断。将整个数组进行排列，可以把重复元素聚集在一起，如果i元素和i-1元素相等，就可以判断是重复元素了
    sort(nums.begin(), nums.end());
    vector<vector<int>> vAll;
    vector<bool> visit(nums.size(), 0);
    vector<int> v;
    dfsPermuteUnique(vAll, nums, visit, v, 0);
    return vAll;
}