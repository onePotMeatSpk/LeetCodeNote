#pragma once
#include<vector>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;
//题目：单词接龙2
//题目描述：按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
//          1、每对相邻的单词之间仅有单个字母不同。
//          2、转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单词。
//          3、sk == endWord
//          给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表[beginWord, s1, s2, ..., sk] 的形式返回。


//思路：用bfs建立有向图，然后用dfs回溯来遍历有向图，并收集路径
//dfs函数（回溯），用来遍历图，以搜寻路径
void dfsFindLadders(unordered_map<string, set<string>>& mapSS, string beginWord, string& endWord, vector<string>& v, vector<vector<string>>& vv)
{
    if (beginWord == endWord)
    {
        vv.push_back(v);
        return;
    }

    for (set<string>::iterator it = mapSS[beginWord].begin(); it != mapSS[beginWord].end(); it++)
    {
        v.push_back(*it);
        dfsFindLadders(mapSS, *it, endWord, v, vv);
        v.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    //bfs建立有向图
    unordered_map<string, int> mapLevel;//mapLevel记录每个单词在节点中的层数
    mapLevel.insert(make_pair(beginWord, 0));
    for (int i = 0; i < wordList.size(); i++)   mapLevel.insert(make_pair(wordList[i], 0));
    unordered_map<string, set<string>> mapSS;//mapSS为字典，记录每个单词在修改其中一个字母之后，可以变为哪些单词

    queue<string> q;
    q.push(beginWord);
    int level = 0, levelNum;
    string cur, next;
    while (!q.empty())
    {
        level++;
        levelNum = q.size();
        while (levelNum--)
        {
            cur = q.front();//cur为现在正在遍历的单词
            q.pop();
            next = cur;//next是cur在修改了其中一个字母后，所变成的单词
            mapSS.insert(make_pair(cur, set<string>()));//为cur建立字典
            for (int i = 0; i < cur.size(); i++)//修改cur中字母
            {
                for (int j = 'a'; j <= 'z'; j++)
                {
                    next[i] = j;
                    if (next == cur || next == beginWord) continue;//next和cur或者beginWord相等，不能添加到字典中，否则会成环
                    if (mapLevel.find(next) == mapLevel.end())   continue;//next不在wordList中，自然不能添加到字典中
                    if (mapLevel[next] != 0 && mapLevel[next] < level)   continue;//next已经在字典中，且是在该层之前，不能添加到字典中，否则会造出一条更长的路
                    //以下两种情况，才是可以添加到字典中的情况
                    if (mapLevel[next] == 0)//next还未添加到字典中，说明从cur来的路径就是第一个可以到达next的路径，自然可以添加到cur的字典中
                    {
                        mapLevel[next] = level;//将next层数设为该层
                        mapSS[cur].insert(next);//将next添加到cur的字典中
                        q.push(next);//将next添加到队列中，供下一层遍历使用
                    }
                    if (mapLevel[next] == level) mapSS[cur].insert(next);//next已添加到字典中，但是就在该层添加的，说明添加到了另一个字母的字典中了，就也可以添加到cur的字典中，代表有不少于1条长度相同的路都可以通到next这里
                }
                next = cur;
            }
        }
    }


    //dfs搜寻路径
    vector<string> v;
    vector<vector<string>> vv;
    dfsFindLadders(mapSS, beginWord, endWord, v, vv);
    for (int i = 0; i < vv.size(); i++)
        vv[i].insert(vv[i].begin(), beginWord);
    return vv;
}