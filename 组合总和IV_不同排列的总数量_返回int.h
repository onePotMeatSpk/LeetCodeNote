#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//����377
//��Ŀ������ܺ�IV_��ͬ���е�������_����int
//��Ŀ����������һ���� ��ͬ ������ɵ����� nums ����һ��Ŀ������ target ������� nums ���ҳ��������ܺ�Ϊ target ��Ԫ����ϵĸ�����
//			��Ŀ���ݱ�֤�𰸷��� 32 λ������Χ��
//			��ע�⣬˳��ͬ�����б�������ͬ����ϡ�

//��ȫ��������Ϊһ�����ֿ���ʹ�ö��
//dp[j]����Ϊjʱ�ķ�������
//dp[0] = 1����������������������������·����Ϊ���еķ������Ҫ�䵽dp[0]
//dp[j] += dp[j - nums[i]]�������ַ���ʹ�ú�j���ֱ�Ϊʹ�úͲ�ʹ��nums[i]
//����Ʒ�󱳰�Ϊ��ϣ��ȱ�������ƷΪ����
//˳��ͬ�����б�������ͬ�����,���Ը���ʹ������
int combinationSum4(vector<int>& nums, int target) {
	vector<int> dp(target + 1, 0);
	dp[0] = 1;

	//�ȱ���������Ʒ
	for (int j = 1; j <= target; j++)
		for (int i = 0; i < nums.size(); i++)
			if(j >= nums[i])	dp[j] += dp[j - nums[i]];

	return dp[target];
}
