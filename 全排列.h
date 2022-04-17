#pragma once
#include<vector>
using namespace std;
//��Ŀ��ȫ����
//��Ŀ����������һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�

//���ݣ�ûɶ��˵��ע��״̬�޸ĺ�״̬�ָ�����
//�ݹ麯��
void permuteCore(vector<int>& nums, vector<bool>& used, vector<vector<int>>& vAll, vector<int>& v)
{
    if(v.size() == nums.size())
    {
        vAll.push_back(v);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
        if(used[i] == false)
        {
            used[i] = true;
            v.push_back(nums[i]);
            permuteCore(nums, used, vAll, v);
            v.pop_back();
            used[i] = false;
        }
}
//������
vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<vector<int>> vAll;
    vector<int> v;
    permuteCore(nums, used, vAll, v);
    return vAll;
}