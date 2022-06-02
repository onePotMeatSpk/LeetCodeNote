#pragma once
#include<vector>
using namespace std;
//����78
//��Ŀ���Ӽ�II_���ظ�Ԫ��
//��Ŀ����������һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ��Ӽ����ݼ�����
//          �⼯ ���� �����ظ����Ӽ������صĽ⼯�У��Ӽ����԰� ����˳�� ���С�


void back(vector<int>& nums, vector<bool>& used, vector<int>& v, vector<vector<int>>& ret, int index = 0)
{
    ret.push_back(v);
    if (index == nums.size())    return;

    for (; index < nums.size(); index++)
    {
        if (index > 0 && nums[index - 1] == nums[index] && used[index - 1] == 0) continue;

        v.push_back(nums[index]);
        used[index] = 1;
        back(nums, used, v, ret, index + 1);
        used[index] = 0;
        v.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<int> v;
    vector<bool> used(nums.size(), 0);
    vector<vector<int>> ret;

    back(nums, used, v, ret);
    return ret;
}