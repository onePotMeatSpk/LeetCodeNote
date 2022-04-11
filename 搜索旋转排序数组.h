#pragma once
#include<vector>
//��Ŀ��������ת��������
// ��Ŀ��������֪����һ�����ǽ������е��������� nums �������е�ֵ���ػ�����ͬ��
//�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת ��ʹ�����Ϊ[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]���±� �� 0 ��ʼ �����������磬[0, 1, 2, 4, 4, 4, 5, 6, 6, 7] ���±� 5 ������ת����ܱ�Ϊ[4, 5, 6, 6, 7, 0, 1, 2, 4, 4] ��
//���� ��ת�� ������ nums ��һ������ target �������дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С���� nums �д������Ŀ��ֵ target ���򷵻� true �����򷵻� false ��
using namespace std;

bool searchInRotatedArray(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) return 1;//target�ҵ���
        if (nums[mid] == nums[l])    l += 1;//�м�ֵ�������ֵ����û�취�ж��ıߵ�������l����һλ�����ж�
        else if (nums[mid] > nums[r])//��ߵ���
        {
            if (target >= nums[l] && target <= nums[mid])    r = mid - 1;//target�����
            else    l = mid + 1;//target���ұ�
        }
        else if (nums[mid] <= nums[r])//�ұߵ���
        {
            if (target >= nums[mid] && target <= nums[r])    l = mid + 1;//target���ұ�
            else    r = mid - 1;//target�����
        }
    }
    return 0;//û���ҵ�target
}