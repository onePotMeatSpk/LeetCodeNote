#pragma once
#include<vector>
#include<unordered_set>
using namespace std;
//����491
//��Ŀ������������
//��Ŀ����������һ���������� nums ���ҳ����������и������в�ͬ�ĵ��������У������������� ����������Ԫ�� ������԰� ����˳�� ���ش𰸡�
//			�����п��ܺ����ظ�Ԫ�أ����������������ȣ�Ҳ���������������е�һ�����������


//˼·��׼ȷ��˵����ʵ�ǲ��ݼ������У���Ϊ������Ԫ����ȡ�
//      ���Ӽ�II��˼·����һ����ֻ��ȥ�ط�����һ����
//      �Ӽ�II��˳����Ҫ��������ȥ�أ���ͨ������ʹ���ظ�Ԫ�ؽ��ڣ�ʹ��һ���ᴩ���в��used��������¼ĳ����Ԫ���Ƿ�ʹ�ã�Ȼ����ÿ���в鿴�ظ�Ԫ�ص�ǰ��Ԫ���Ƿ�δ��ʹ�á�
//      �����˳����Ҫ�����Բ��ɶ��������򣬼�Ȼȥ�ص�Ŀ�ģ��Ƿ�ֹһ���ڳ����ظ������Կ�����ÿ��������һ��setUsed������¼ĳ�����Ƿ�ʹ�ù������for����������ĳ���֣��������Ѿ���setUsed�У�˵�����ڸò��Ѿ���ʹ�ù�����Ӧ���ٱ�ʹ���ˡ�

//����
//
void back(vector<int>& nums, vector<int>& v, vector<vector<int>>& ret, int index = 0) {

    if (v.size() >= 2)   ret.push_back(v);
    if (index == nums.size())    return;

    unordered_set<int> setUsed;//��ÿ��������setUsed��ר�ż�¼�ò�����ֵ�ʹ�����
    for (; index < nums.size(); index++)
    {
        if (v.size() && nums[index] < v.back())  continue;//��ǰ���ֲ��������Ҫ����ʹ��
        if (setUsed.find(nums[index]) != setUsed.end())  continue;//��ǰ�������ظ����֣����Ѿ��ڸò��е�ǰ��֦Ѿʹ�ù������Բ�Ӧ����ʹ���ˣ�������ظ�

        setUsed.insert(nums[index]);//����ǰԪ�ط���setUsed���Ա�ʾ�Ѿ�ʹ�ù�
        v.push_back(nums[index]);
        back(nums, v, ret, index + 1);
        v.pop_back();
    }

}

//������
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> v;
    vector<vector<int>> ret;

    back(nums, v, ret);
    return ret;
}