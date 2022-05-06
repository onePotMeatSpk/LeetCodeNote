#pragma once
#include<string>
using namespace std;
//力扣10
//题目：正则表达式匹配
//题目描述：给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//			'.' 匹配任意单个字符
//			'*' 匹配零个或多个前面的那一个元素
//			所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

//递归
//思想：递归函数将s、p整体都分为两部分：当前匹配部分和残留未匹配部分
//      如果当前匹配部分可以匹配成功，那么整体能否匹配成功，取决于残留未匹配部分能否匹配成功
//      使用递归函数，来判断残留未匹配部分能否匹配成功
//      不断循环，直到到达p或s的末尾

//辅函数，递归函数
bool dfsIsMatch(const string& s, const string& p, int indexS = 0, int indexP = 0)
{
    //p、s都到达末尾，说明p、s中所有字符都匹配成功了，ture
    if (indexS == s.size() && indexP == p.size())    return true;
    //仅有p到达末尾，s未到达末尾，说明s中仍有字符未匹配，false
    if (indexP == p.size())  return false;
    //仅有s到达末尾,p未到达末尾
    if (indexS == s.size())
    {
        //如果p中残留的，全是 a* 或者 .* 这种，可以匹配s中0个字符的表达式，true
        //这里使用递归，以一个 a* 或者 .* 为基本单位，一层一层往后检查
        if (indexP <= p.size() - 2 && p[indexP + 1] == '*')  return dfsIsMatch(s, p, indexS, indexP + 2);
        //否则false
        return false;
    }

    //情况1：p[indexP]是字母，并且p[indexP + 1]是'*'
    if (indexP <= p.size() - 2 && p[indexP] != '.' && p[indexP + 1] == '*')
    {
        //那么p[indexP]和p[indexP + 1]这俩字符，可匹配s中从s[indexS]开始的、连续的、所有的、等于p[indexP]的字符
        //也就是说，从s[indexS]开始，s中有多少个连续的等于p[indexP]的字符，p中这俩字符就可以匹配多少个
        //根据匹配的s中等于p[indexP]的字符的数量的不同，这里可以有多种不同的解决方案
        //如果s[indexS + i] == p[indexP]，说明s[indexS]至s[indexS + i]间（前闭后闭）的所有字符都和p[indexP]相等，那么p中这俩字符可以匹配到s[indexS]至s[indexS + i]间的所有字符，这就是其中一种匹配的方案
        //这个方案能否成功，取决于s[indexS + i]之后（不包含s[indexS + i]）的残留未匹配部分，和p[indexP + 1]之后（不包含p[indexP + 1]）的残留未匹配部分，这两者能否匹配成功了
        //一旦有一种方案成功了，那么整个字符串就是可以成功匹配的，true
        for (int i = 0; s[indexS + i] == p[indexP]; i++)
            if (dfsIsMatch(s, p, indexS + i + 1, indexP + 2))    return true;
        //如果s中从s[indexS]开始，没有哪怕1个字符和p[indexP]相等，那么p[indexP]和p[indexP + 1]这俩字符就无法在s中匹配到字符，这俩字符就应该作废
        //从p[indexP + 2]开始，重新对s的从s[indexS]开始的部分进行匹配，
        return dfsIsMatch(s, p, indexS, indexP + 2);
    }
    //情况2：p[indexP]是字母，并且p[indexP + 1]不是'*'
    if (p[indexP] != '.')
        //p[indexP]是字母
        //p[indexP]==s[indexS]时，p[indexP]、s[indexS]匹配成功
        //      整个字符串能够匹配成功，就取决于s[indexS]之后（不包含s[indexS]）的残留未匹配部分，和p[indexP]之后（不包含p[indexP]）的残留未匹配部分，这两者能否匹配成功了
        //p[indexP]!=s[indexS]时，p[indexP]、s[indexS]匹配失败，那么整个字符串的匹配到此彻底失败
        return s[indexS] == p[indexP] ? dfsIsMatch(s, p, indexS + 1, indexP + 1) : false;

    //情况3：p[indexP]是'.'，并且p[indexP + 1]是'*'
    if (indexP <= p.size() - 2 && p[indexP] == '.' && p[indexP + 1] == '*')
    {
        //与情况1相似，但是有所不同
        //不同的地方在于：情况1要看p[indexP]和p[indexP + 1]这俩字符，能否匹配到s中等于p[indexP]的字符；而情况3不需要，因为'.*'可以匹配零个或多个任意字符
        //所以情况3中，p中这俩字符可以从s[indexS]开始，一路向后、毫无阻拦地进行匹配，直到将s中字符用完
        //所以情况3中，根据这俩字符匹配到的s中从s[indexS]开始的字符的数量的不同，可以有多种不同解决方案，
        for (int i = 0; indexS + i <= s.size(); i++)
            if (dfsIsMatch(s, p, indexS + i, indexP + 2))    return true;
        //如果所有的解决方案都失败，那整个字符串匹配失败
        return false;
    }
    //情况4：p[indexP]是'.'，并且p[indexP + 1]不是'*'
    if (p[indexP] == '.')
        //p[indexP]是'.'，所以p[indexP]可以一定匹配到s[indexS]，不管s[indexS]是什么
        //整个字符串能够匹配成功，就取决于s[indexS]之后（不包含s[indexS]）的残留未匹配部分，和p[indexP]之后（不包含p[indexP]）的残留未匹配部分，这两者能否匹配成功了
        return dfsIsMatch(s, p, indexS + 1, indexP + 1);

    //默认false
    return false;
}

//主函数
bool isMatch(string s, string p) {
    return dfsIsMatch(s, p);
}