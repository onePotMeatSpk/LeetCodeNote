#pragma once
#include<string>
#include<stack>
using namespace std;
//力扣20
//题目：有效的括号
//题干：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
		//有效字符串需满足：
		//	左括号必须用相同类型的右括号闭合。
		//	左括号必须以正确的顺序闭合。


//见到')'、']'、'}'，就检查前方是否是'('、'['、'{'
//若是，则两者都弹栈，继续运行
//若否，则false
bool isValid(string s) {
    if (s.size() % 2 == 1)
        return false;

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);

        if (st.top() == ')')
        {
            st.pop();
            if (st.empty() || st.top() != '(')
                return false;
            st.pop();
        }
        else if (st.top() == ']')
        {
            st.pop();
            if (st.empty() || st.top() != '[')
                return false;
            st.pop();
        }
        else if (st.top() == '}')
        {
            st.pop();
            if (st.empty() || st.top() != '{')
                return false;
            st.pop();
        }

    }

    if (st.empty())
        return true;
    else
        return false;
}

