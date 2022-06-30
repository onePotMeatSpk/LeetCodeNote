#pragma once
#include<vector>
using namespace std;
//����977
//��Ŀ�����������ƽ��
//��Ŀ����������һ���� �ǵݼ�˳�� ������������� nums������  ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����

//���ҳ�����ֵ��С�Ļ�׼��base����base���ҵľ���ֵ������base
//�ٴ�base��ʼ���ֱ���������ȡƽ��������¼���ɣ����ƹ鲢�����еĹ鲢
vector<int> sortedSquares(vector<int>& nums) {

    //�ҳ�����ֵ��С�ĵ�
    int base = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (abs(nums[i]) <= abs(nums[base]))
            base = i;
        else
            break;
    }

    //�鲢ƽ��
    vector<int> ret;
    int l = base, r = base + 1;
    while (l >= 0 && r < nums.size())
    {
        if (abs(nums[l]) < abs(nums[r]))
        {
            ret.push_back(nums[l] * nums[l]);
            l--;
        }
        else
        {
            ret.push_back(nums[r] * nums[r]);
            r++;
        }
    }

    while (l >= 0)
    {
        ret.push_back(nums[l] * nums[l]);
        l--;
    }

    while (r < nums.size())
    {

        ret.push_back(nums[r] * nums[r]);
        r++;
    }

    return ret;
}