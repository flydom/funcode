// 复制复杂链表

// 第一步: 赋值每一个节点
void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode *pNode = pHead;
    while (pNode != NULL)
    {
        ComplexListNode *pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pNode->m_pNext = pCloned;

        pNode = pCloned->m_pNext;
    }
}

// 第二步: 设置每一个复制节点的复杂指针
void ConnectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode *pRealNode = pHead;
    while (pRealNode != NULL)
    {
        ComplexListNode *pCloned = pRealNode->m_pNext;
        if (pRealNode->m_pSibling != NULL)
        {
            pCloned->m_pSibling = pRealNode->m_pSibling->m_pNext;
        }

        pRealNode = pCloned->m_pNext;
    }
}

// 第三步: 分拆链表
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = NULL;
    ComplexListNode *pClonedNode = NULL;

    if (pNode != NULL)
    {
        pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pClonedNode->m_pNext;
        pClonedHead = pClonedNode;
    }

    while (pNode != NULL)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pClonedNode->m_pNext;
    }

    return pClonedHead;
}

// 组合三步
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}