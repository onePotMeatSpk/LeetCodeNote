#pragma once
#include<vector>
using namespace std;
//��Ŀ��ʡ������/����Ȧ
//��Ŀ�������� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ����������ô���� a ����� c ���������
//		ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�
//		����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ���������� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
//		���ؾ����� ʡ�� ��������

//������ȱ�������visit�н��Ѿ��������ĵ���1
//O(N^2),O(N)��NΪ����������
void findCircleNumCore(vector<vector<int>>& isConnected, vector<bool>& visited, int i)
{
    if (visited[i] == 1) return;//�õ��Ѿ����뵽ʡ�ݣ������õ�
    visited[i] = 1;//����ʡ��
    for (int j = 0; j < isConnected.size(); j++)
        if (isConnected[i][j] == 1)  findCircleNumCore(isConnected, visited, j);//�õ���������������ڣ��͵ݹ�������
}
int findCircleNum(vector<vector<int>>& isConnected) {
    if (isConnected.size() == 0)  return 0;
    int num = 0;
    vector<bool> visited(isConnected.size(), 0);//0��ʾ�õ���δ����ʡ�ݣ�1��ʾ�Ѿ�����
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (visited[i] == 1) continue;//�õ��Ѿ����뵽ʡ�ݣ������õ�
        findCircleNumCore(isConnected, visited, i);//����õ���һ��ʡ���еĵ�ȫ������
        num++;//ʡ�ݼ�һ
    }
    return num;
}