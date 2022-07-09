#pragma once
#include<string>
#include<stack>
#include<vector>
using namespace std;
//力扣150
//题目：逆波兰表达式求值
//题干：根据 逆波兰表示法，求表达式的值。
        //有效的算符包括 + 、 - 、 * 、 / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。


//按照逆波兰表达式的规则，符号前的两位，为操作该符号的数字，用栈模拟即可
int evalRPN(vector<string>& tokens) {
    stack<int> s;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            int c;
            if (tokens[i] == "+")
                c = a + b;
            else if (tokens[i] == "-")
                c = a - b;
            else if (tokens[i] == "*")
                c = a * b;
            else if (tokens[i] == "/")
                c = a / b;
            s.push(c);
        }
        else
            s.push(atoi(tokens[i].c_str()));
    }

    return s.top();
}