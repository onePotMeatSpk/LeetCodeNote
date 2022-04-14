#pragma once
#include<vector>
#include<algorithm>

using namespace std;


//!!!���Ӷȹ��ߵĽⷨ���ݹ飬���Ӷ�ΪO(6^n)
//int dicesProbabilityCore(vector<int>& dice, int index, int sum, int& n, vector<int>& freq)
//{
//	//�ݹ���ֹ�������ݹ�����������
//	if (index == n)
//	{
//		freq[sum]++;
//		return -1;
//	}
//
//	while (dice[index] <= 6)
//	{
//		dicesProbabilityCore(dice, index + 1, sum + dice[index], n, freq);
//		dice[index]++;
//	}
//	dice[index] = 1;
//	return -1;
//}
//
//vector<double> dicesProbability(int n) {
//	vector<double> vectorProbability;
//	if (n == 0)
//		return vectorProbability;
//	vector<int> vectorFrequency(6 * n + 1);
//	vector<int> vectorDice(n, 1);
//
//	//�ݹ�����ӽ������ͳ��
//	dicesProbabilityCore(vectorDice, 0, 0, n, vectorFrequency);
//
//	//�������н�����ܴ���
//	double frequencyAll = 0;
//	for (int i = n; i <= 6 * n; i++)
//		frequencyAll += vectorFrequency[i];
//
//	double probability;
//	for (int i = n; i <= 6 * n; i++)
//	{
//			probability = vectorFrequency[i] / frequencyAll;
//			vectorProbability.push_back(probability);
//	}
//
//	return vectorProbability;
//}


//���Ӷȵ͵Ľⷨ����̬�滮�����Ӷ�ΪO(n^2)
vector<double> dicesProbability(int n)
{
	vector<double> Probability;
	if (n == 0)	return Probability;

	vector<double> preProbability(6 * n + 1);
	vector<double> nowProbability(6 * n + 1);

	fill(preProbability.begin(), preProbability.end(), 1.0 / 6);
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j <= 6 * i; j++)
			for (int k = 1; k <= 6; k++)
				nowProbability[j + k] += (preProbability[j] / 6);
		preProbability = nowProbability;
		fill(nowProbability.begin(), nowProbability.end(), 0);
	}


	for (int i = n; i <= 6 * n; i++)
		Probability.push_back(preProbability[i]);

	return Probability;
}