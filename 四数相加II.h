#pragma once
#include<unordered_map>
#include<vector>
using namespace std;
//����454
//��Ŀ���������II
//��ɣ������ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺
        //0 <= i, j, k, l < n
        //nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

//˼·
//���ȶ��� һ��unordered_map��key��a��b����֮�ͣ�value ��a��b����֮�ͳ��ֵĴ�����
//������A�ʹ�B���飬ͳ����������Ԫ��֮�ͣ��ͳ��ֵĴ������ŵ�map�С�
//����int����count������ͳ�� a + b + c + d = 0 ���ֵĴ�����
//�ڱ�����C�ʹ�D���飬�ҵ���� 0 - (c + d) ��map�г��ֹ��Ļ�������count��map��key��Ӧ��valueҲ���ǳ��ִ���ͳ�Ƴ�����
//��󷵻�ͳ��ֵ count �Ϳ�����
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> umap;

    for (int i = 0; i < nums1.size(); i++)
        for (int j = 0; j < nums2.size(); j++)
            umap[nums1[i] + nums2[j]]++;

    int ret = 0;
    for (int i = 0; i < nums3.size(); i++)
        for (int j = 0; j < nums4.size(); j++)
            ret += umap[-(nums3[i] + nums4[j])];

    return ret;
}