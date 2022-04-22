#pragma once
#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//��Ŀ��ȫ���к��ظ�Ԫ��
//��Ŀ����������һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�

//dfs����
void dfsPermuteUnique(vector<vector<int>>& vAll, vector<int>& nums, vector<bool>& visit, vector<int>& v, int index)
{
    if (index == nums.size())
    {
        vAll.push_back(v);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {

        //����Ϊȫ���л��٣��������У��˴�Ϊ����һ��
        //����Ԫ�أ�i&&nums[i] == nums[i - 1]��!visit[i - 1]����&&��
        //i&&nums[i] == nums[i - 1]��i-1��i��ȣ�˵��iΪ�ظ�Ԫ�أ��п��ܵ����ظ����У���Ҫ�ر���
        //!visit[i - 1]����i��i-1��ȵ�����£�1)���i-1û�б�ռ�ݣ���ô��ǰλ��������i����Ϊ�ض��ᵼ���ظ����У�2)���򣬿�����i����Ϊ���ᵼ���ظ�����
        //  ��{1,1,1,2}Ϊ��
        //  1)�����λ�õ�һ��1���ڶ�λ�õڶ���1���򲻻�����ظ�����Ϊ�ڶ���1ǰ����1��ռ����϶��Ǹ�λռ�ģ�Ҳ����˵��ǰ1�ǵ�ǰλ�����ĵ�һ������Ȼ����ֱ���á�
        //  2)�����λ�õ�һ��1���ڶ�λ�õ�����1���������ظ�����Ϊ������1ǰ����1δռ����˵����ǰλ����һ��ȫ�����У�����ʹ�ù�ǰ��1����Ϊforѭ��������ǰ��1�ſճ�����
        if (i && nums[i] == nums[i - 1] && !visit[i - 1]) continue;

        if (visit[i])    continue;
        visit[i] = 1;
        v.push_back(nums[i]);
        dfsPermuteUnique(vAll, nums, visit, v, index + 1);
        visit[i] = 0;
        v.pop_back();
    }
}

//������
vector<vector<int>> permuteUnique(vector<int>& nums) {
    //����Ϊȫ���л��٣��������У��˴�Ϊ����һ��
    //�ظ����������ɢ���ڸ����Ļ������Ѷ��ظ��������жϡ�����������������У����԰��ظ�Ԫ�ؾۼ���һ�����iԪ�غ�i-1Ԫ����ȣ��Ϳ����ж����ظ�Ԫ����
    sort(nums.begin(), nums.end());
    vector<vector<int>> vAll;
    vector<bool> visit(nums.size(), 0);
    vector<int> v;
    dfsPermuteUnique(vAll, nums, visit, v, 0);
    return vAll;
}