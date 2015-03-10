
BinaryTreeNode* BuildCore(int *startPreorder, int *endPreorder,
                          int *startInorder, int *endInorder)
{
    int rootValue = startPreorder[0];

    // 构建树或子树的根节点
    BinaryTreeNode *root = new BinaryTreeNode();
    if (root == NULL)
    {
        return NULL;
    }
    
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    // 只有一个节点
    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
        {
            return root;
        }
        else
        {
            printf("Invalid input.!\n");
            return NULL;
        }
    }

    // 到中序序列中找根节点
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
    {
        rootInorder++;
    }

    if (rootInorder > endInorder)
    {
        printf("Invalid input.!\n");
        return NULL;
    }

    // 递归构建中序遍历根节点中的左右子树
    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0)
    {
        root->m_pLeft = BuildCore(startPreorder + 1, leftPreorderEnd,
                                  startInorder, rootInorder - 1);
    }
    
    if (leftLength < endPreorder - startPreorder)
    {
        root->m_pRight = BuildCore(leftPreorderEnd + 1, endPreorder,
                                   rootInorder + 1, endInorder);
    }

    return root;
}

BinaryTreeNode* BuildBiTree(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
    {
        return NULL;
    }

    return BuildCore(preorder, preorder + length - 1,
                     inorder, preorder + length - 1);
        
}
