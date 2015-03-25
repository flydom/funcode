// 寻找单链表倒数第K个节点

// 方法一
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if (pListHead == NULL || k == 0)
    {
        return NULL;
    }

    unsigned int count = 1;
    ListNode *pTempNode = pListHead;
    while (pTempNode->m_pNext != NULL)
    {
        count++;
        pTempNode = pTempNode->m_pNext;
    }

    if (count < k)
    {
        return NULL;
    }

    unsigned int index = count - k + 1;
    ListNode *pNode = pListHead;
    for (unsigned int i = 1; i < index; i++)
    {
        pNode = pNode->m_pNext;
    }
    
    return pNode;
}

// 方法二
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if (pListHead == NULL || k == 0)
    {
        return NULL;
    }

    ListNode *pAhead = pListHead;

    for (unsigned int i = 0; i < k - 1; i++)
    {
        if (pAhead->m_pNext == NULL)
        {
            return NULL;
        }
        
        pAhead = pAhead->m_pNext;
    }
    
    ListNode *pBehind = pListHead;
    while (pAhead->m_pNext != NULL)
    {
        pBehind = pBehind->m_pNext;
        pAhead = pAhead->m_pNext;
    }

    return pBehind;
}



