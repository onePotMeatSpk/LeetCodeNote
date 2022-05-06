#pragma once
#include<math.h>
#include<vector>
using namespace std;
//力扣650
//题目：只有两个按键的键盘
//题目描述：最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：
//          Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
//          Paste（粘贴）：粘贴 上一次 复制的字符。
//          给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。返回能够打印出 n 个 'A' 的最少操作次数。


//动态规划
//辅函数，如果n为合数，返回n的一个非1因子，如果n为质数，返回1
int factorOf(int n)
{
    int sq = sqrt(n);
    for (int i = 2; i <= sq; i++)
        if (n % i == 0)  return i;
    return 1;
}

//主函数
int minSteps(int n) {
    //dp[i]，表示从1变为i所需要的步骤，这不就是将数字扩大i倍所需要的步骤吗。
    vector<int> dp(n + 1, 0);
    //变为1需要0步，不符合下面的规则
    //所以从2开始遍历
    for (int i = 2; i <= n; i++)
    {
        //取得i的一个因子factor0
        int factor0 = factorOf(i);
        //如果i为质数，那么变为i就需要i步
        //从1变成i，只经历一步：1乘上i本身，从而变为i
        //所以，从1变为i就需要i步：第1步copy，后面i-1步paste
        if (factor0 == 1)    dp[i] = i;
        //如果i为质数，那么变为i就需要dp[factor0]+dp[factor1]步，factor0、factor1是i的两个非1因子
        //从1变成i，就要经历两步：1、1乘上factor0，从而变成factor0，2、factor0再乘上factor1，从而变为i
        //所以，从1变为i就需要dp[factor0]+dp[factor1]步
        else
        {
            int factor1 = i / factor0;
            dp[i] = dp[factor0] + dp[factor1];
        }
    }
    return dp[n];
}