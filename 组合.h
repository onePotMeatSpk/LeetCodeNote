#pragma once
#include<vector>
using namespace std;
//����77
//��Ŀ�����
//��Ŀ������������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�����԰� �κ�˳�� ���ش𰸡�


//k����Ҫ��ʣ�����ָ�������֦��
//index����ʼ����������
void back(const int& n, int k, int index, vector<int>& v, vector<vector<int>>& ret)
{
    if (k == 0) {
        ret.push_back(v);
        return;
    }
    if (k > n - index + 1)   return;

    for (; index <= n; index++)
    {
        v.push_back(index);
        back(n, k - 1, index + 1, v, ret);
        v.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<int> v;
    vector<vector<int>> ret;
    back(n, k, 1, v, ret);
    return ret;
}