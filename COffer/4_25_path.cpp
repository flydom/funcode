// 二叉树中求某和的路径

void FindPathCore(BinaryTreeNode *pRoot, 
                  std::vector<int> &path,
                  int expectedSum, 
                  int &currentSum)
{
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    // 叶节点并且总和相等
    bool isLeaf = (pRoot->m_pLeft == NULL) && (pRoot->m_pRight == NULL);
    if (currentSum == expectedSum && isLeaf)
    {
        printf("A path is found:");
        std::vector <int>::iterator iter = path.begin();
        for (; iter != path.end(); iter++)
        {
            printf("%d\t", *iter);
        }
        printf("\n");
    }

    // 非叶节点，继续遍历
    if (pRoot->m_pLeft != NULL)
    {
        FindPathCore(pRoot->m_pLeft, path, expectedSum, currentSum);
    }
    
    if (pRoot->m_pRight != NULL)
    {
        FindPathCore(pRoot->m_pRight, path, expectedSum, currentSum);
    }

    // 返回父节点是要退出当前节点
    path.pop_back();
}
