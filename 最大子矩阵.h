#pragma once
#include<vector>
#include<algorithm>
using namespace std;





vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    //³��
    vector<int> position(4, 0);
    int raws = matrix.size();
    if (raws == 0)   return position;
    int cols = matrix[0].size();
    if (cols == 0)   return position;

    int maxSum = matrix[0][0], sum = 0;//maxSumһ��Ҫ��ʼ��Ϊmatri[0][0]����0,�Է�������ʵ�Ǹ���
    int i = 0, j = 0, k = 0;
    int index;//������ǵ�ǰ�Ӷε���߽�
    vector<int> numsOneD(cols, 0);

    //��ά��ѹ��i��j����֮�����Ϊһά����
    for (i = 0; i < raws; i++)
    {
        fill(numsOneD.begin(), numsOneD.end(), 0);
        for (j = i; j < raws; j++)
        {
            //����һά����
            for (k = 0; k < cols; k++)
                numsOneD[k] += matrix[j][k];

            //ÿ�ֶ�̬�滮ǰ���г�ʼ��
            index = 0;
            sum = numsOneD[0];
            //�������ֵ���������
            if (sum > maxSum)
            {
                maxSum = sum;
                position[0] = i;
                position[1] = 0;
                position[2] = j;
                position[3] = 0;
            }

            //��̬�滮������ֶκ�
            for (k = 1; k < cols; k++)
            {
                if (sum < 0)
                {
                    sum = numsOneD[k];
                    index = k;
                }
                else
                    sum += numsOneD[k];
                //�������ֵ���������
                if (sum > maxSum)
                {
                    maxSum = sum;
                    position[0] = i;
                    position[1] = index;
                    position[2] = j;
                    position[3] = k;
                }
            }
        }
    }

    return position;
}