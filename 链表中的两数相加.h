#pragma once
#include<stack>
#include"单向链表.h"
#include<iostream>
using namespace std;


////辅助栈+大数加法，时间复杂度O(N)，空间复杂度0(N)
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//    //鲁棒
//    if (!l1) return l2;
//    if (!l2) return l1;
//
//    //s1存l1元素，s2存l2元素，s3存l3元素
//    stack<int> s1, s2, s3;
//    //upper为本位相加产生的进位，sum为本位的和
//    int upper = 0, sum = 0;
//
//    //遍历l1、l2，将其元素入栈
//    ListNode* p = l1;
//    while (p)
//    {
//        s1.push(p->val);
//        p = p->next;
//    }
//    p = l2;
//    while (p)
//    {
//        s2.push(p->val);
//        p = p->next;
//    }
//
//    //普通的大数相加
//    while (s1.size() || s2.size())
//    {
//        //求本位和
//        if (s1.empty())
//        {
//            sum = s2.top() + upper;
//            s2.pop();
//        }    
//        else if (s2.empty())
//        {
//            sum = s1.top() + upper;
//            s1.pop();
//        }
//        else
//        {
//            sum = s1.top() + s2.top() + upper;
//            s1.pop();
//            s2.pop();
//        }
//
//        //求进位
//        upper = sum / 10;
//        //将本位入栈
//        s3.push(sum % 10);
//        
//    }
//
//    //处理最终的进位
//    if (upper)
//        s3.push(upper);
//
//    //先将l3的头摘出来
//    ListNode* head = new ListNode(s3.top());
//    s3.pop();
//    ListNode* pre = head;
//    ListNode* newNode = NULL;
//    
//    //创建l3后续节点
//    while (s3.size())
//    {
//        newNode = new ListNode(s3.top());
//        s3.pop();
//        pre->next = newNode;
//        pre = newNode;
//    }
//
//    return head;
//}

//反转链表+大数加法，时间复杂度O(N)，空间复杂度O(1)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	//鲁棒

	//l1与l2反转
	
	//两者大数相加

	//l1与l2反转

	//return
}