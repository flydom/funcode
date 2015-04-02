// 判断二叉树B是否是二叉树A的子树


bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot2 == NULL)
    {
        return true;
    }

    if (pRoot1 == NULL)
    {
        return false;
    }

    if (pRoot1->m_nValue != pRoot2->m_nValue)
    {
        return false;
    }

    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
            DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;

    if (pRoot1 != NULL && pRoot2 != NULL)
    {
        if (pRoot1->m_nValue == pRoot2->m_nValue)
        {
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        }

        if (result != true)
        {
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        }

        if (result != true)
        {
            result = HasSubtree(pRoot1->m_pRight, pRoot2);
        }
    }


    return result;
}
