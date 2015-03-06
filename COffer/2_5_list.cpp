/*
  从尾到头反过来打印单链表的每个节点。
*/ 

#include "stdio.h"
#include "tchar.h"

struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
}

// 栈
void PrintListFromTail2Head(ListNode *Head)
{
	std::stack<ListNode *> nodes;
	
	ListNode *pNode = Head;
	
	while (pNode != Null)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	
	while (!nodes.empty())
	{
		nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
}

// 递归
void PrintListFromTail2Head(ListNode *Head)
{
	if (Head != NULL) 
	{
		if (Head->m_pNext != NULL)
		{
			PrintListFromTail2Head(Head->m_pNext);
		}
		
		printf("%d\t", pNode->m_nKey);
	}
}


