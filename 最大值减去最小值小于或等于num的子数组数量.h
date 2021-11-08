#pragma once
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

//辅助函数：更新deque
//flag参数为true表示后入新元素，为false表示前出旧元素
void updateDeque(deque<int>& dMax, deque<int>& dMin, const int& updateNum, bool flag)
{
    if (flag)//后入新元素
    {
        while ((!dMin.empty()) && (updateNum < dMin.back()))
            dMin.pop_back();
        dMin.push_back(updateNum);

        while ((!dMax.empty()) && (updateNum > dMax.back()))
            dMax.pop_back();
        dMax.push_back(updateNum);
    }
    else//前出旧元素
    {
        if (updateNum == dMin.front())
            dMin.pop_front();
        if (updateNum == dMax.front())
            dMax.pop_front();
    }
}

//核心函数
int getCount(const vector<int>& nums, const int& len, const int& num)
{
    int i = 0, j = 0;
    int count = 0;
    deque<int> dequeMax, dequeMin;
    dequeMax.push_back(nums[0]);
    dequeMin.push_back(nums[0]);

    while (j < len)
    {
        if (dequeMax.front() - dequeMin.front() <= num)
        {
            j++;
            if (j < len)
                updateDeque(dequeMax, dequeMin, nums[j], true);
            else
                break;
        }
        else
        {
            count += (j - i);
            updateDeque(dequeMax, dequeMin, nums[i], false);
            i++;
        }
    }

    count += (((j - i) * ((j - i) + 1)) / 2);
    return count;
}



////主函数
//int main()
//{
//    int n, num;
//    cin >> n;
//    cin >> num;
//    vector<int>nums(n);
//    for (int i = 0; i < n; i++)
//        cin >> nums[i];
//    cout << getCount(nums, n, num);
//    return 0;
//}
