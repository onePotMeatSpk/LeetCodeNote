#pragma once
#include<string>
using namespace std;
//剑指 Offer 58 - II. 
//左旋转字符串
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
			//比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

//将整个字符串，分为前后两部分，前部要被旋转到后方
//先将整个字符串旋转，这样，前部就被旋转到后方了，但是此时，前部分、后部分的内部也是倒序
//再分别旋转前部分、后部分的内部，使其由倒序变成正序



string reverseLeftWords(string s, int n)
{
	reverse(s.begin(), s.end());
	reverse(s.begin(), s.begin() + s.size() - n);
	reverse(s.begin() + s.size() - n, s.end());
	
	return s;
}