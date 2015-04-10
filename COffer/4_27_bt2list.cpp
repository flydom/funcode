// 二叉树转双向链表，不能创建新节点

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if (pNode == NULL)
    {
        return;
    }

    BinaryTreeNode *pCurrent = pNode;
    if (pCurrent->m_pLeft != NULL)
    {
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    }
    
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != NULL)
    {
        (*pLastNodeInList)->m_pRight = pCurrent;
    }

    *pLastNodeInList = pCurrent;
    if (pCurrent->m_pRight != NULL)
    {
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
    }
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = NULL;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    BinaryTreeNode *pListHead = pLastNodeInList;
    while (pListHead != NULL && pListHead->m_pLeft != NULL)
    {
        pListHead = pListHead->m_pLeft;
    }

    return pListHead;
}
