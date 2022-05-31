#pragma once
#include<unordered_map>
#include<string>
using namespace std;
//力扣17
//题目：电话号码的字母组合
//题目描述：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//          给数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


//回溯：号码中的每个数字为单独一层，在每层中遍历该数字对应的各字母
void back(const string& digits, int index, string& s, vector<string>& ret, unordered_map<char, vector<char>>& map) {
    if (index == digits.size())
    {
        ret.push_back(s);
        return;
    }

    for (int i = 0; i < map[digits[index]].size(); i++)
    {
        s += map[digits[index]][i];
        back(digits, index + 1, s, ret, map);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)  return vector<string>();
    unordered_map<char, vector<char>> map;
    map.insert(make_pair<char, vector<char>>('2', { 'a','b','c' }));
    map.insert(make_pair<char, vector<char>>('3', { 'd','e','f' }));
    map.insert(make_pair<char, vector<char>>('4', { 'g','h','i' }));
    map.insert(make_pair<char, vector<char>>('5', { 'j','k','l' }));
    map.insert(make_pair<char, vector<char>>('6', { 'm','n','o' }));
    map.insert(make_pair<char, vector<char>>('7', { 'p','q','r','s' }));
    map.insert(make_pair<char, vector<char>>('8', { 't','u','v' }));
    map.insert(make_pair<char, vector<char>>('9', { 'w','x','y','z' }));

    string s;
    vector<string> ret;
    back(digits, 0, s, ret, map);
    return ret;
}