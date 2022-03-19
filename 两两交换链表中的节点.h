#pragma once
#include"单向链表.h"
//题目：两两交换链表中的节点
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进
//行节点交换）。

//解题思路：将要交换的两节点称为节点组，并设置四个节点，他们的关系如图：
//          lastNode->formerNode->laterNode->nextNode
//          formerNode表示节点组的第一个节点，laterNode则表示第二个，lastNode和nextNode不需赘述
//          交换之后的节点位置如图：
//          lastNode->laterNode->formerNode->nextNode
//          可看出有三个指向关系需要调整，程序中只需要依次改变这三个指向即可
//          交换完一次之后，将整个结构向后移即可



ListNode* swapPairs(ListNode* head) {
    if ((head == NULL) || (head->next == NULL))  return head;
    ListNode* dummy = new ListNode(0, head);//建立虚拟节点，使其next指向头结点
    ListNode* lastNode = dummy;
    ListNode* formerNode = head;
    ListNode* laterNode = head->next;
    ListNode* nextNode = NULL;


    while (laterNode && formerNode)
    {
        nextNode = laterNode->next;

        //进行节点交换（改变三个指向）
        lastNode->next = laterNode;
        laterNode->next = formerNode;
        formerNode->next = nextNode;

        //将结构向后推进
        lastNode = formerNode;
        if ((nextNode == NULL) || (nextNode->next == NULL))  break;
        else {
            formerNode = nextNode;
            laterNode = nextNode->next;
        }
    }

    return dummy->next;
}