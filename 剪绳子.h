#pragma once
#include<vector>
using namespace std;
//��Ŀ��һ����Ϊ n �����ӣ������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m-1]��
//		���� k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
//		ʱ�õ������˻���18��

//��̬�滮��ʱ�临�Ӷ�O(N2)���ռ临�Ӷ�O(N)
int cuttingRope(int n) {
	if (n == 0)	return 0;
	vector<int> f(n + 1);
	f[0] = 1;
	f[1] = 1;
	int maxAll = 1, maxNow = 0;
	
	for (int i = 2; i <= n; i++)
	{
		maxNow = 0;
		for (int j = 1; j <= i / 2; j++)
			maxNow = max(i - j, f[i - j]) * max(j, f[j]) > maxNow ? max(i - j, f[i - j]) * max(j, f[j]) : maxNow;
		//ת�Ʒ��̽��ͣ������Ӽ�Ϊ���Σ���֤m>1���������ο���ѡ��������¼����߲��������ܳ˻����ķ������Ƿֱ������θ���
		//				�ĳ˻�������Ӷηֱ��ڼ��򲻼���ѡ�����ļ��ɡ�
		f[i] = maxNow;
		maxAll = f[i] > maxAll ? f[i] : maxAll;
	}

	return maxAll;
}