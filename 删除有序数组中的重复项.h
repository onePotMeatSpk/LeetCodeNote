#pragma once
#include<vector>
using namespace std;
//����26
//��Ŀ��ɾ�����������е��ظ���
//��Ŀ����������һ�� �������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��


//���ַ�
//������27�Ƴ�Ԫ��˼·��ͬ��ֻ������ָ�������Ŀ�꣬�������ض����֣�������ǰ�����ֲ�ͬ�����֣����µĲ��ظ����֣���
int removeDuplicates(vector<int>& nums) {
    if (nums.empty())
        return 0;

    int l = 1, r = 1;

    while (r < nums.size())
    {
        if (nums[r] == nums[r - 1])
            r++;
        else
            nums[l++] = nums[r++];
    }

    return l;
}
