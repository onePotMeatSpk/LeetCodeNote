#pragma once
#include<vector>
using namespace std;
//����78
//��Ŀ���Ӽ�
//��Ŀ����������һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//			�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��

//�Ӽ����⣺�μ���������¼

//����
void back(vector<int>& nums, vector<int>& v, vector<vector<int>>& ret, int index = 0)
{
    ret.push_back(v);//�Ӽ������У��Ӽ������һ�����������ڵݹ���ֹ����֮�У�Ӧ����֮ǰ
                     //�����֮�У��ͻᵼ�£�ֻ�е�����ĩβ���Ӽ������ܱ����
                     //���ܶ��Ӽ����ǲ�����ĩβԪ�صģ����Ա�����һ�������һ�Σ��������ܱ�֤�����Ӽ��������
    if (index == nums.size())    return;

    for (; index < nums.size(); index++)
    {
        v.push_back(nums[index]);
        back(nums, v, ret, index + 1);
        v.pop_back();
    }
}

//������
vector<vector<int>> subsets(vector<int>& nums) {
    //�κμ��϶��п��Ӽ�
    vector<vector<int>> ret;
    vector<int> v;

    back(nums, v, ret);
    return ret;
}