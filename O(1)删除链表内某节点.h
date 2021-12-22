#pragma once
#include"单向链表.h"

//时间复杂度O(1)
//思想：将删除节点的next节点的值覆盖到删除节点，然后将删除节点的next指向下下个节点，这样就避免了传统节点删除思想中遍历得
//		到删除节点的pre的O(N)的复杂度。
//缺点：一：该算法必须提前得知要删除节点的指针，这是很不方便的，因为删除节点的一贯思想是已知数值，而不是已知节点
//		二：如果第二参数传入的节点并不是head列表中的节点，而是另一个列表中的节点，则该算法会发生错误
void deleteOneNode(ListNode*& head, ListNode* deleteNode)
{
	//头为空或要删节点为空
	if (!head || !deleteNode)	return;
	//删除的是头结点，则将头结点向后移动
	if (head == deleteNode)
	{
		head = head->next;
		return;
	}
	//删除的是尾结点，则采用传统节点删除算法（复杂度为O(N)），但这并不会导致整个算法复杂度上升，((N-1)*O(1)+O(N))/N=O(1)
	if (deleteNode->next == NULL)
	{
		ListNode* pPre = NULL;
		ListNode* pCur = head;
		while (pCur != deleteNode)
		{
			pPre = pCur;
			pCur = pCur->next;
		}
		pPre->next = pCur->next;
		return;
	}
	//核心算法
	deleteNode->val = deleteNode->next->val;
	deleteNode->next = deleteNode->next->next;
}