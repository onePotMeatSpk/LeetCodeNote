#pragma once
#include<string>
using namespace std;

//力扣8
//题目：字符串转换整数 (atoi)
//题目描述：请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
            //函数 myAtoi(string s) 的算法如下：
            //
            //读入字符串并丢弃无用的前导空格
            //检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
            //读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
            //将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
            //如果整数数超过 32 位有符号整数范围[−231, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
            //返回整数作为最终结果。
            //注意：
            //
            //本题中的空白字符只包括空格字符 ' ' 。
            //除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。



string getValidString(string& s)
{
    string ret;
    bool validStart = 0;
    bool not0Start = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (validStart == 0)
        {
            if (s[i] == ' ')
            {
                continue;
            }

            if (s[i] == '+' || s[i] == '-')
            {
                validStart = 1;
                ret += s[i];
                continue;
            }

            if (s[i] >= '0' && s[i] <= '9')
            {
                if (s[i] != '0')
                {
                    not0Start = 1;
                    ret += s[i];
                }
                validStart = 1;
                continue;
            }

            break;
        }
        else
        {
            if (not0Start == 0)
            {
                if (s[i] == '0')
                    continue;
                if (s[i] >= '1' && s[i] <= '9')
                {
                    not0Start = 1;
                    ret += s[i];
                    continue;
                }
            }
            else
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    ret += s[i];
                    continue;
                }
            }

            break;

        }
    }

    return ret;
}

int myAtoiCre(string& s, bool isPos)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++)
        num = num * 10 + (s[i] - '0') * (isPos ? 1 : -1);
    return num;
}


int myAtoi(string s) {
    string validS = getValidString(s);


    if (validS.size() == 0)   return 0;
    if (validS[0] == '-')
    {
        string numS = validS.substr(1, validS.size() - 1);
        string numMin = to_string(INT_MAX);
        numMin[numMin.size() - 1] = numMin[numMin.size() - 1] + 1;

        //长度超标，溢出
        if (numS.size() > numMin.size())
            return INT_MIN;
        //长度和INT_MIN一致，但是字典序更大，还是溢出
        if (numS.size() == numMin.size() && numS > numMin)
            return INT_MIN;
        //其余情况，都是非溢出，可以进行转换
        return myAtoiCre(numS, 0);
    }
    else if (validS[0] == '+')
    {
        string numS = validS.substr(1, validS.size() - 1);
        string numMax = to_string(INT_MAX);

        //长度超标，溢出
        if (numS.size() > numMax.size())
            return INT_MAX;
        //长度和INT_MAX一致，但是字典序更大，还是溢出
        if (numS.size() == numMax.size() && numS > numMax)
            return INT_MAX;
        //其余情况，都是非溢出，可以进行转换
        return myAtoiCre(numS, 1);
    }
    else
    {
        string numS = validS;
        string numMax = to_string(INT_MAX);

        //长度超标，溢出
        if (numS.size() > numMax.size())
            return INT_MAX;
        //长度和INT_MAX一致，但是字典序更大，还是溢出
        if (numS.size() == numMax.size() && numS > numMax)
            return INT_MAX;
        //其余情况，都是非溢出，可以进行转换
        return myAtoiCre(numS, 1);
    }

    return 0;
}