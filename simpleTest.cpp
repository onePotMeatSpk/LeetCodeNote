#pragma once
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<typeinfo>
#include"四数之和.h"
using namespace std;

void removeExtraSpace(string& s)
{
    int i = 0, j = 0;
    while (j < s.size())
    {
        if (s[j] != ' ')
        {
            if (j == 0 || s[j - 1] != ' ')
                s[i++] = s[j++];
            else
            {
                s[i++] = ' ';
                s[i++] = s[j++];
            }
        }
        else
            j++;
    }

    s.resize(i);
}


void main()
{
	string s = "  hello world 
        ";
    removeExtraSpace(s);
	return;
}
