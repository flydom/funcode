// 判断是否是二叉搜索树的后续遍历


bool VerifySquenceOfBST(int sequence[], int length)
{
    if (sequence == NULL || length <= 0)
    {
        return false;
    }

    int root = sequence[length - 1];

    // 找左子树节点
    int i = 0;
    for (; i < length - 1; i++)
    {
        if (sequence[i] > root)
        {
            break;
        }
    }

    // 判断右子树是否有节点小于根节点
    int j = i;
    for (; j < length - 1; j++)

    {
        if (sequence[j] < root)
        {
            return false;
        }
    }

    // 判断左子树是否BST
    bool left = true;
    if (i > 0)
    {
        left = VerifySquenceOfBST(sequence, i);
    }

    // 判断右子树是否BST
    bool right = true; 
    if (i < length - 1)
    {
        right = VerifySquenceOfBST(sequence + i, length - i - 1);
    }

    return left && right;
}

