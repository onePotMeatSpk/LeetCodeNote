#pragma once
#include<vector>
using namespace std;
//����283
//��Ŀ���ƶ���
//��Ŀ����������һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
            //��ע�� �������ڲ���������������ԭ�ض�������в�����


//���ַ�
//ǰ�벿�֣�������27�Ƴ�Ԫ��˼·��ͬ��ֻ�����Ƴ�Ԫ��ȷ��Ϊ0��
//��벿�֣�����ָ��֮�������λ�ã����0
void moveZeroes(vector<int>& nums) {
    int l = 0, r = 0;

    while (r < nums.size())
    {
        if (nums[r] == 0)
            r++;
        else
            nums[l++] = nums[r++];
    }

    while (l < nums.size())
        nums[l++] = 0;
}
