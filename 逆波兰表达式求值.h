#pragma once
#include<string>
#include<stack>
#include<vector>
using namespace std;
//����150
//��Ŀ���沨�����ʽ��ֵ
//��ɣ����� �沨����ʾ��������ʽ��ֵ��
        //��Ч��������� + �� - �� * �� / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��


//�����沨�����ʽ�Ĺ��򣬷���ǰ����λ��Ϊ�����÷��ŵ����֣���ջģ�⼴��
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