#pragma once
#include<string>
#include<stack>
using namespace std;
//力扣1047
//题目：删除字符串中的所有相邻重复项
//题干：给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
        //在 S 上反复执行重复项删除操作，直到无法继续删除。
        //在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。



//和力扣20有效的括号，思路类似，都是用栈
string removeDuplicates(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {

        if (!st.empty() && s[i] == st.top())
            st.pop();
        else
            st.push(s[i]);
    }

    string newS;
    while (!st.empty())
    {
        newS += st.top();
        st.pop();
    }

    reverse(newS.begin(), newS.end());
    return newS;
}