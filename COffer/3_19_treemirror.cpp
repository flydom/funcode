// 输出二叉树的镜像


void MirrorRecursively(BinaryTreeNode *pNode)
{
    if (pNode == NULL || (pNode->m_pLeft == NULL && pNode->m_pRight == NULL))
    {
        return;
    }

    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if (pNode->m_pLeft)
    {
        MirrorRecursively(pNode->m_pLeft);
    }

    if (pNode->m_pRight)
    {
        MirrorRecursively(pNode->m_pRight);
    }
}

void MirrorIteratively(BinaryTreeNode* pRoot)
{
    std::stack <BinaryTreeNode *> nodes;

    while (pRoot || !nodes.empty())
    {
        // 交换子节点
        if (pRoot != NULL)
        {
            BinaryTreeNode *pTemp = pRoot->m_pLeft;
            pRoot->m_pLeft = pRoot->m_pRight;
            pRoot->m_pRight = pTemp;	
        }

        if (pRoot != NULL)
        {
            nodes.push(pRoot);
            pRoot = pRoot->m_pLeft;
        }
        else
        {
            pRoot = nodes.top();
            nodes.pop();
            pRoot = pRoot->m_pRight;
        }
    }
}
