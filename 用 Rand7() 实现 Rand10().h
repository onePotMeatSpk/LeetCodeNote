#pragma once
//力扣470
//题目：用 Rand7() 实现 Rand10()
//题目描述：给定方法 rand7 可生成 [1,7] 范围内的均匀随机整数，试写一个方法 rand10 生成 [1,10] 范围内的均匀随机整数。
			//你只能调用 rand7() 且不能调用其他方法。请不要使用系统的 Math.random() 方法。
			//每个测试用例将有一个内部参数 n，即你实现的函数 rand10() 在测试时将被调用的次数。请注意，这不是传递给 rand10() 的参数。

//参考https://leetcode.cn/problems/implement-rand10-using-rand7/solution/xiang-xi-si-lu-ji-you-hua-si-lu-fen-xi-zhu-xing-ji/
int rand10() {
    int ret = 49;
    while (ret > 40)
        ret = (rand7() - 1) * 7 + rand7();

    ret = ret % 10;
    return ret ? ret : 10;
}