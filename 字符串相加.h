#pragma once
#include<string>
using namespace std;
//题目：字符串相加
//题目描述：给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//          你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

//思路：普通字符串相加，注意大数即可。

string addStrings(string num1, string num2) {
    string numNew(max(num1.size(), num2.size()) + 1, '0');
    int i = num1.size() - 1, j = num2.size() - 1, k = numNew.size() - 1, flag = 0, sum = 0;
    while (i >= 0 && j >= 0)
    {
        sum = num1[i--] - '0' + num2[j--] - '0' + flag;
        flag = sum / 10;
        numNew[k--] = '0' + sum % 10;
    }
    while (i >= 0)
    {
        sum = num1[i--] - '0' + flag;
        flag = sum / 10;
        numNew[k--] = '0' + sum % 10;
    }
    while (j >= 0)
    {
        sum = num2[j--] - '0' + flag;
        flag = sum / 10;
        numNew[k--] = '0' + sum % 10;
    }

    numNew[0] = flag ? '1' : '0';
    return flag ? numNew : numNew.substr(1, numNew.size() - 1);
}