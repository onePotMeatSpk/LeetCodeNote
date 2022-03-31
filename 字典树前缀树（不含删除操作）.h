#pragma once
#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class Trie {
public:
    bool isEnd;
    Trie* next[26];
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (!next[word[i] - 'a'])
                next[word[i] - 'a'] = new Trie();
            cur = next[word[i] - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (!next[word[i] - 'a'])
                return false;
            cur = next[word[i] - 'a'];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* cur = this;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!next[prefix[i] - 'a'])
                return false;
            cur = next[prefix[i] - 'a'];
        }
        return true;
    }
};


//class Trie {
//public:
//    int count;//记录以当前字母结尾的单词的数量
//    int prenum;//记录，以当前字母结尾的字符串的，单词的数量
//    Trie** nextChar;
//public:
//    Trie() {
//        count = 0;
//        prenum = 0;
//        nextChar = new Trie * [26];
//        for (int i = 0; i < 26; i++)
//            nextChar[i] = NULL;
//    }
//
//    void insert(string word) {
//        Trie* cur = this;
//        for (int i = 0; i < word.size(); i++)
//        {
//            cur->prenum++;
//            if (cur->nextChar[word[i] - 'a'] != NULL)
//                cur = cur->nextChar[word[i] - 'a'];
//            else
//            {
//                cur->nextChar[word[i] - 'a'] = new Trie();
//                cur = cur->nextChar[word[i] - 'a'];
//            }
//        }
//        cur->prenum++;
//        cur->count++;
//    }
//
//    bool search(string word) {
//        Trie* cur = this;
//        for (int i = 0; i < word.size(); i++)
//        {
//            if (cur->nextChar[word[i] - 'a'] != NULL)
//                cur = cur->nextChar[word[i] - 'a'];
//            else
//                return false;
//        }
//        if (cur->count)  return true;
//        return false;
//    }
//
//    bool startsWith(string prefix) {
//        Trie* cur = this;
//        for (int i = 0; i < prefix.size(); i++)
//        {
//            if (cur->nextChar[prefix[i] - 'a'] != NULL)
//                cur = cur->nextChar[prefix[i] - 'a'];
//            else
//                return false;
//        }
//
//        if (cur->prenum)  return true;
//        return false;
//    }
//};