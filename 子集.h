#pragma once
#include<vector>
using namespace std;
//����78
//��Ŀ���Ӽ�
//��Ŀ����������һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//			�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��

//���ݺ������󳤶�Ϊneed���Ӽ�
void back(vector<int>& nums, vector<int>& v, vector<vector<int>>& ret, int need, int index = 0)
{
    if (need == 0)
    {
        ret.push_back(v);
        return;
    }
    if (index == nums.size())    return;

    for (; index < nums.size(); index++)
    {
        v.push_back(nums[index]);
        back(nums, v, ret, need - 1, index + 1);
        v.pop_back();
    }
}

//������
vector<vector<int>> subsets(vector<int>& nums) {
    //�κμ��϶��п��Ӽ�
    vector<vector<int>> ret;
    ret.push_back({});
    if (nums.empty())    return ret;


    vector<int> v;
    //���ȴ�1��nums.size()������ͬ���ȣ��ֱ����Ӽ�
    for (int i = 1; i <= nums.size(); i++)
        back(nums, v, ret, i);
    return ret;
}