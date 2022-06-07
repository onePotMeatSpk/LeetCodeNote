#pragma once
#include<queue>
using namespace std;
//力扣295
//题目： 数据流的中位数
//题目描述：中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
            //例如，
            //
            //[2, 3, 4] 的中位数是 3
            //
            //[2, 3] 的中位数是(2 + 3) / 2 = 2.5
            //
            //设计一个支持以下两种操作的数据结构：
            //
            //void addNum(int num) - 从数据流中添加一个整数到数据结构中。
            //double findMedian() - 返回目前所有元素的中位数。


//思路：使用两个堆，一个大顶堆、一个小顶堆，大顶堆存放较小一半元素，小顶堆存放较大一半元素，两者的顶即为整体的中间的数字

//实现方法1：使用priority_queue
class MedianFinder {
public:

    MedianFinder() {
    }

    // 维持堆数据平衡，并保证左边堆的最大值小于或等于右边堆的最小值
    void addNum(int num) {
        /*
        * 当两堆的数据个数相等时候，左边堆添加元素。
        * 采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后
        * 将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。
        * 同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。
        */

        if (maxHeap.size() == minHeap.size())
        {
            minHeap.push(num);
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        else
        {
            maxHeap.push(num);
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
    }

    double findMedian() {
        if (maxHeap.size() == 0 && minHeap.size() == 0)  return 0;

        if (maxHeap.size() == minHeap.size())    return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
        else    return maxHeap.top();
    }

public:
    // 最大堆，存储左边一半的数据，堆顶为最大值
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // 最小堆， 存储右边一半的数据，堆顶为最小值
    priority_queue<int, vector<int>, greater<int>> minHeap;
};


//实现方法2：手撕堆
class MyHeap
{
private:
	vector<int> nums;
	bool flagMaxMin;

public:
	MyHeap(bool flag) :flagMaxMin(flag) {}

	void push(int num)
	{
		nums.push_back(num);
		pushHeap(nums.size() - 1);
	}

	void pop()
	{
		popHeap(nums.size());
		nums.pop_back();
	}

	int top()
	{
		if (nums.empty())	return INT_MIN;
		return nums[0];
	}

	int size()
	{
		return nums.size();
	}

private:
	void pushHeap(int hole)
	{
		int val2Push = nums[hole];
		int parent = (hole - 1) / 2;

		while (hole > 0 && (flagMaxMin ? val2Push > nums[parent] : val2Push < nums[parent]))
		{
			nums[hole] = nums[parent];
			hole = parent;
			parent = (hole - 1) / 2;
		}

		nums[hole] = val2Push;
	}

	void popHeap(int len)
	{
		int hole = 0;
		int val2Pop = nums[hole];
		int secondChild = hole * 2 + 2;

		while (secondChild < len)
		{
			if (flagMaxMin ? nums[secondChild - 1] > nums[secondChild] : nums[secondChild - 1] < nums[secondChild])	secondChild--;

			nums[hole] = nums[secondChild];
			hole = secondChild;
			secondChild = hole * 2 + 2;
		}

		if (secondChild == len)
		{
			secondChild--;
			nums[hole] = nums[secondChild];
			hole = secondChild;
		}

		swap(nums[hole], nums[len - 1]);
		nums[len - 1] = val2Pop;

		if (hole != len - 1)	pushHeap(hole);
	}
};


class MedianFinder {
public:

    MedianFinder() :maxHeap(1), minHeap(0) {}

    void addNum(int num)
    {
        if (maxHeap.size() == minHeap.size())
        {
            minHeap.push(num);
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        else
        {
            maxHeap.push(num);
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
    }

    double findMedian() {
        if (maxHeap.size() == 0 && minHeap.size() == 0)  return 0;

        if (maxHeap.size() == minHeap.size())    return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
        else    return maxHeap.top();
    }

public:
    // 最大堆，存储左边一半的数据，堆顶为最大值
    MyHeap maxHeap;
    // 最小堆， 存储右边一半的数据，堆顶为最小值
    MyHeap minHeap;
};