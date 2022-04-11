#pragma once
#include<vector>
using namespace std;
//��Ŀ�����������еĵ�һԪ��
//��Ŀ����������һ������������ɵ��������飬����ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ�Ρ������ҳ�������ֻ����һ�ε��Ǹ�����

//���ַ���ʱ�临�Ӷ�O(logN)���ռ临�Ӷ�O(1),
//������뻭ͼ��⣡���㷨��Ҫ��֤����ÿ�ε����������䳤�ȶ�Ϊ�������������ܼȰ���target���ְ������Գɶ�Ԫ��
int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid, wingLen;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        wingLen = mid - l;//������
        if (nums[mid] == nums[mid - 1])//��midԪ����ǰ��Ԫ�����
        {
            if (wingLen & 1) l = mid + 1;//��������Ϊ�棬��target��mid֮��Ϊ��֤�����䳤����Ϊ�������ʶ�����Ҫ��midԪ����������䣬l = mid + 1
            else    r = mid;//��������Ϊż����target��mid֮ǰ��Ϊ��֤�����䳤����Ϊ�������ʶ���Ҫ��midԪ����������䣬r = mid 
        }
        else if (nums[mid] == nums[mid + 1])//��midԪ�����Ԫ�����
        {
            if (wingLen & 1) r = mid - 1;//��������Ϊ�棬��target��mid֮ǰ��Ϊ��֤�����䳤����Ϊ�������ʶ�����Ҫ��midԪ����������䣬r = mid - 1
            else    l = mid;//��������Ϊż����target��mid֮��Ϊ��֤�����䳤����Ϊ�������ʶ���Ҫ��midԪ����������䣬l = mid 
        }
        else    return nums[mid];//��ǰ�󶼲���ȣ����ǹµ�Ԫ��
    }
    return nums[l];//����ֻʣһ��Ԫ����ʱ�����ǹµ�Ԫ��
}

//����㷨Ϊ���ϵ��㷨��javaʵ�֣���˼���뱾�˷���һ�������Ǹ�Ϊ���
// ʡȥ�˸���mid��ǰ��Ԫ�صĹ�ϵ��������ż������ֱ���Ĺ��̣�
// ����������Ϊ����ʱ��ֱ�ӽ�midǰ��һλ�������ͽ������ȱ�Ϊ��ż��
// ���е�mid������nums[mid+1]���Ƚϣ�����midǰ��֮���������ȵ������Ϊż�����ȣ�����mid��mid+1�Ƚ���ʵ���Ǳ�����mid-1��mid�Ƚϣ�
// ̫TM�����ˣ�����������
//class Solution {
//    public int singleNonDuplicate(int[] nums) {
//        int l = 0, r = nums.length - 1, m;
//        while (l < r) {
//            m = l + (r - l) / 2;
//            if (m % 2 == 1) {
//                m--;
//            }
//            if (nums[m] == nums[m + 1]) {
//                l = m + 2;
//            }
//            else {
//                r = m;
//            }
//        }
//        return nums[l];
//    }
//}