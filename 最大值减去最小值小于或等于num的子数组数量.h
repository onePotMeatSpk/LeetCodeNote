#pragma once
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

//��������������deque
//flag����Ϊtrue��ʾ������Ԫ�أ�Ϊfalse��ʾǰ����Ԫ��
void updateDeque(deque<int>& dMax, deque<int>& dMin, const int& updateNum, bool flag)
{
    if (flag)//������Ԫ��
    {
        while ((!dMin.empty()) && (updateNum < dMin.back()))
            dMin.pop_back();
        dMin.push_back(updateNum);

        while ((!dMax.empty()) && (updateNum > dMax.back()))
            dMax.pop_back();
        dMax.push_back(updateNum);
    }
    else//ǰ����Ԫ��
    {
        if (updateNum == dMin.front())
            dMin.pop_front();
        if (updateNum == dMax.front())
            dMax.pop_front();
    }
}

//���ĺ���
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



////������
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
