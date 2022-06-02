#pragma once
#include<vector>
using namespace std;
//����46
//��Ŀ��ȫ����
//��Ŀ����������һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�

//���ݣ�ûɶ��˵��ע��״̬�޸ĺ�״̬�ָ�����
//�ݹ麯��
void back(vector<int>& nums, vector<bool>& used, vector<vector<int>>& ret, vector<int>& v)
{
    if(v.size() == nums.size())
    {
        ret.push_back(v);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i] == 1)    continue;

        used[i] = 1;
        v.push_back(nums[i]);
        back(nums, used, ret, v);
        v.pop_back();
        used[i] = 0;
    }
    
}
//������
vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), 0);
    vector<vector<int>> ret;
    vector<int> v;

    back(nums, used, ret, v);
    return ret;
}