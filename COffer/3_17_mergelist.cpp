// 合并两个增序链表，合并后依然增序

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL)
    {
        return pHead2;
    }

    if (pHead2 == NULL)
    {
        return pHead1;
    }

    ListNode *pNewHead = NULL;
    if (pHead1->m_nValue <= pHead2->m_nValue)
    {
        pNewHead = pHead1;
        pNewHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pNewHead = pHead2;
        pNewHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }

    return pNewHead;
}
