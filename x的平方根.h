#pragma once
#include<vector>
using namespace std;
//力扣69
//题目：x的平方根
//题目描述：给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//          由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。


//二分法，注意使用longlong类型，以防止溢出
int mySqrt(int x) {
    int l = 0, r = x, mid = 0;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        long long sq0 = (long long)mid * mid;
        long long sq1 = (long long)(mid + 1) * (mid + 1);

        if (sq0 > x)
            r = mid - 1;
        else if (sq0 == x || (sq0 < x && sq1 > x))
            return mid;
        else if (sq1 <= x)
            l = mid + 1;
    }

    return -1;
}