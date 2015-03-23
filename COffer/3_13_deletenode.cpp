// O(1)时间度删除单链表指定节点

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if (pListHead == NULL || pToBeDeleted == NULL)
    {
        return;
    }
    
    // 链表只有一个头节点
    if ((*pListHead)->m_pNext == NULL && pToBeDeleted == *pListHead)
    {
        delete pToBeDeleted;
        *pListHead = NULL;
        pToBeDeleted = NULL;
    }
    // 删除非尾节点
    else if (pToBeDeleted->m_pNext != NULL)
    {
        ListNode *pDeletedNext =  pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pDeletedNext->m_nValue;
        pToBeDeleted->m_pNext = pDeletedNext->m_pNext;
        
        delete pDeletedNext;
        pDeletedNext = NULL;
    }
    // 删除尾节点
    else
    {
        ListNode *pTempNode = *pListHead;
        while (pTempNode->m_pNext != pToBeDeleted)
        {
            pTempNode = pTempNode->m_pNext;
        }

        pTempNode->m_pNext = NULL;

        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }

    return;
}