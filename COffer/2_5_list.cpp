/*
  从尾到头反过来打印单链表的每个节点。
  struct ListNode
  {
      int m_nValue;
	  ListNode *m_pNext;
  }
*/ 

// 栈
void PrintListFromTail2Head_Iteratively(ListNode *pHead)
{
	std::stack <ListNode *> nodes;
	
	ListNode *pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	
	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

// 递归
void PrintListFromTail2Head_Recursively(ListNode *pHead)
{
	if (pHead != NULL) 
	{
		if (pHead->m_pNext != NULL)
		{
			PrintListFromTail2Head_Rec(pHead->m_pNext);
		}
		
		printf("%d\t", pHead->m_nValue);
	}
}

