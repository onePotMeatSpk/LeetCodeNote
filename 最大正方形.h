#pragma once
#include<vector>
using namespace std;
//��Ŀ�����������
//��Ŀ��������һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ��������������

//dp��O(N),O(N)
//dp�����У�dp[i][j]��ʾ����[i][j]��Ϊ���½ǵ������εı߳�
//ʹ��һ������max������¼�ѱ���������������߳�
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int max = 0;//max����ʾ�Ѿ����������У���������εı߳�
    int leftSquare = 0;//leftSquare����ʾ��[i][j]����ߵ�Ԫ��[i][j-1]Ϊ���½ǵ������εı߳�
    int upSquare = 0;//upSquare����ʾ��[i][j]���ϱߵ�Ԫ��[i-1][j]Ϊ���½ǵ������εı߳�
    vector<vector<int>> matrixInt(m, vector<int>(n, 0));//matrixInt����dp���飬��¼��[i][j]Ϊ���½ǵ������εı߳�
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrixInt[i][j] = matrix[i][j] == '1' ? 1 : 0;
    //��������ߺ����ϱߣ���Ϊ�������ѭ������������������������Ļ����ᵼ�´��뷱�����������ȱ���
    for (int i = 0; i < m; i++)  if (matrixInt[i][0] == 1)   max = 1;
    for (int j = 0; j < n; j++)  if (matrixInt[0][j] == 1)   max = 1;
    //��ѭ���壬�������ಿ��
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            //[i][j]��Ϊ0���ǲ��������������Դ�Ϊ���½�
            if (matrixInt[i][j] == 0)   continue;
            //[i][j]��Ϊ0
            leftSquare = matrixInt[i][j - 1];
            upSquare = matrixInt[i - 1][j];
            //leftSquare��upSquare���
            if (leftSquare == upSquare)
            {
                //leftSquareΪ0����ô[i][j]�����䱾������ɵ������ε����½�
                if (leftSquare == 0);
                //leftSquare��Ϊ0���˴����Ի�ͼ���
                else if (matrixInt[i - upSquare][j - leftSquare] != 0)   matrixInt[i][j] = leftSquare + 1;
                else    matrixInt[i][j] = leftSquare;
            }
            //leftSquare��upSquare���ȣ���ͼ���
            else    matrixInt[i][j] = min(leftSquare, upSquare) + 1;
            //����max
            max = matrixInt[i][j] > max ? matrixInt[i][j] : max;
        }

    return max * max;
}