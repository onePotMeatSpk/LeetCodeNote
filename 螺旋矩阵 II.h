#pragma once
#include<vector>
using namespace std;
//力扣59
//题目：螺旋矩阵 II
//题目描述：给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。


//思路：模拟螺旋矩阵就是了

enum DIRECTION
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));//返回数组
    int end = n * n;//最终数字
    int count = 1;//当前要填数字

    DIRECTION derection = RIGHT;//当前行进方向
    int borderLeft = -1, borderRight = n, borderUp = -1, borderDown = n;//初始化各边界
    int border = borderRight;//当前行进方向的边界
    int base = 0;//当前正在填充的行/列
    int i = 0;//当前所在行/列中的位置
    bool flag = 0;//表示当前行进方向中，判断当前位置i与边界border关系，应用>还是<？0则>，1则<

    while (count <= end)
    {
        //
        //根据行进方向不同，填充当前行/列
        for (; flag ? i > border : i < border;)
        {
            switch (derection)
            {
            case RIGHT://解释RIGHT，其他情况类似
                //当前方向为RIGHT，base = 0，i < border = borderRight，i从0开始
                //表示当前正在填充第0行，的第[0, borderRight)列，每填一列，则i++以填下列，且count++以填下数
                ret[base][i++] = count++;
                break;
            case DOWN:
                ret[i++][base] = count++;
                break;
            case LEFT:
                ret[base][i--] = count++;
                break;
            case UP:
                ret[i--][base] = count++;
                break;
            }
        }

        //填充当前行/列完毕
        //更新各参数
        switch (derection)
        {
        case RIGHT://解释RIGHT，其他情况类似
            borderUp++;//更新旧边界，当前行进方向是RIGHT，填充的必定是矩阵顶部，故而borderUp++，表示顶部边界下移
            derection = DOWN;//新行进方向，当前行进方向是RIGHT，则接下来方向必定往下拐，开始填充矩阵右部
            flag = 0;//更新判断符号，当前行进方向是RIGHT，则接下来方向必定往下拐，应该与底部边界比较大小，符号应用<
            border = borderDown;//设置新行进方向的边界，当前行进方向是RIGHT，则接下来方向必定往下拐，边界应是底部边界
            base = --i;//设置新行进方向的行/列，当前行进方向是RIGHT，填充时的最后一次i++，导致i已经越过borderRight，应该--i，以贴着右边界，填充矩阵右部
            i = borderUp + 1;//新方向从何处开始遍历，当前行进方向是RIGHT，则接下来方向必定往下拐，应该从顶部开始走起
            break;
        case DOWN:
            borderRight--;
            derection = LEFT;
            flag = 1;
            border = borderLeft;
            base = --i;
            i = borderRight - 1;
            break;
        case LEFT:
            borderDown--;
            derection = UP;
            flag = 1;
            border = borderUp;
            base = ++i;
            i = borderDown - 1;
            break;
        case UP:
            borderLeft++;
            derection = RIGHT;
            flag = 0;
            border = borderRight;
            base = ++i;
            i = borderLeft + 1;
            break;
        }
    }

    return ret;
}