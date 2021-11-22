#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<time.h>
#include"单向链表.h"
#include"数字在排序数组中出现的次数.h"
#include"0至n-1中缺失的数字.h"
#include"左右两边子数组的和相等.h"
#include"数组中数字出现的次数.h"
#include"和为s的两个数字.h"
#include"和为s的连续正数序列.h"
#include"翻转单词顺序.h"
#include"左旋转字符串.h"
#include"滑动窗口的最大值.h"
#include"队列的最大值.h"
#include"n个筛子的点数.h"
#include"圆圈中最后剩下的数字.h"
#include"股票的最大利润.h"
#include"求1+2+…+n.h"
#include"不用加减乘除做加法.h"
#include"最大值减去最小值小于或等于num的子数组数量.h"
#include"最大子矩阵.h"
#include"将单向链表按某值划分为左边小，中间相等，右边大的形式.h"
#include"链表中的两数相加.h"
#include"单向链表每k个节点之间逆序.h"
#include"删除无序链表中值重复出现的节点.h"

using namespace std;

int main()
{
    vector<int> v1 = { 5,1,2,3,1,2,3,4,4 };
    ListNode* l1 = createList(v1);
    printList(l1);
    ListNode* l3 = remove_rep(l1);
    printList(l3);

    return 0;
}

