// 反转单链表

// 非递归
ListNode* ReverseList(ListNode* pHead)
{
    ListNode *pPrev = NULL;
    ListNode *pCurr = pHead;
    while (pCurr != NULL)
    {
        ListNode *pNext = pHead->m_pNext;
        if (pNext == NULL)
        {
            break;
        }
        
        pCurr->m_pNext = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
        pNext = pNext->m_pNext;
    }
    
    return pCurr;
}

// 递归
ListNode* ReverseCore(ListNode* pPrev, ListNode* pCurr, ListNode* pNext)
{
    pCurr->m_pNext = pPrev;
    if (pNext == NULL)
    {
        return pCurr;
    }

    return ReverseCore(pCurr, pNext, pNext->m_pNext);
}
