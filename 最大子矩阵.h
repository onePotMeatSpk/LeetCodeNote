#pragma once
#include<vector>
#include<algorithm>
using namespace std;





vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    //鲁棒
    vector<int> position(4, 0);
    int raws = matrix.size();
    if (raws == 0)   return position;
    int cols = matrix[0].size();
    if (cols == 0)   return position;

    int maxSum = matrix[0][0], sum = 0;//maxSum一定要初始化为matri[0][0]而非0,以防最大和其实是负数
    int i = 0, j = 0, k = 0;
    int index;//用来标记当前子段的左边界
    vector<int> numsOneD(cols, 0);

    //降维：压缩i、j两行之间矩阵为一维矩阵
    for (i = 0; i < raws; i++)
    {
        fill(numsOneD.begin(), numsOneD.end(), 0);
        for (j = i; j < raws; j++)
        {
            //更新一维矩阵
            for (k = 0; k < cols; k++)
                numsOneD[k] += matrix[j][k];

            //每轮动态规划前进行初始化
            index = 0;
            sum = numsOneD[0];
            //更新最大值及最大坐标
            if (sum > maxSum)
            {
                maxSum = sum;
                position[0] = i;
                position[1] = 0;
                position[2] = j;
                position[3] = 0;
            }

            //动态规划求最大字段和
            for (k = 1; k < cols; k++)
            {
                if (sum < 0)
                {
                    sum = numsOneD[k];
                    index = k;
                }
                else
                    sum += numsOneD[k];
                //更新最大值及最大坐标
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