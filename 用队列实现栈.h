#pragma once
#include<queue>
using namespace std;
//����225
//��Ŀ���ö���ʵ��ջ
//��ɣ������ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����


//һ�����У���ģ��ջ����Ԫ�ص�ʱ��ֻҪ������ͷ����Ԫ�أ��������һ��Ԫ���⣩ ������ӵ�����β������ʱ��ȥ����Ԫ�ؾ���ջ��˳���ˡ�
class MyStack {
private:
    queue<int> q;
    int topNum;
public:
    MyStack() {
    }

    //O(1)
    void push(int x) {
        q.push(x);
        topNum = x;
    }


    int pop() {
        int temp;

        int len = q.size();
        //������ͷ����ǰlen - 2��Ԫ�أ�������ӵ�����β��
        for (int i = 0; i < len - 2; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        //��¼��len - 1��Ԫ��Ϊ�µ�topNum��Ȼ��������ӵ�����β��
        topNum = q.front();
        q.pop();
        q.push(topNum);

        //������len��Ԫ��
        temp = q.front();
        q.pop();
        return temp;
    }

    //O(1)
    int top() {
        return topNum;
    }

    //O(1)
    bool empty() {
        return q.empty();
    }
};