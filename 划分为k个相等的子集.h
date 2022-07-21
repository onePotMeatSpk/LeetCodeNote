#pragma once
#include<vector>
#include<algorithm>
using namespace std;
//����698
//��Ŀ������Ϊk����ȵ��Ӽ�
//��Ŀ����������һ����������  nums ��һ�������� k���ҳ��Ƿ��п��ܰ��������ֳ� k ���ǿ��Ӽ������ܺͶ���ȡ�


//����
bool back(vector<int>& nums, vector<bool>& used, int k, int& sum, int need, int index = 0)
{
    if (k == 0)
        return true;

    for (int i = index; i < nums.size() && nums[i] <= need; i++)
    {
        if (used[i] == 1)
            continue;

        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
            continue;

        used[i] = 1;
        if (nums[i] == need)
        {
            //ÿ������һ���Ӽ����ʹ���λ��ʼ������һ���Ӽ�
            if (back(nums, used, k - 1, sum, sum, 0))
                return true;
        }
        else
            //�����Ӽ�û���������ʹ���һλ��ʼ�������ǰ�Ӽ�
            if (back(nums, used, k, sum, need - nums[i], index + 1))
                return true;
        used[i] = 0;
    }

    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int i : nums)
        sum += i;

    //����
    if (sum % k != 0)
        return false;

    sum = sum / k;
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), 0);
    //����
    return back(nums, used, k, sum, sum);
}