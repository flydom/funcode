// 判断序列是否是栈的弹出序列

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    if (pPush == NULL || pPop == NULL || nLength <= 0)
    {
        return false;
    }
    
    bool bPossible = false;
    const int *pTempPush = pPush;
    const int *pNextPop = pPop;

    std::stack <int> stackData;
    stackData.push(*pTempPush);

    while (pNextPop - pPop < nLength)
    {   
        while (pTempPush - pPush < nLength)
        {
            // 判断是否是出栈元素
            if (stackData.top() == *pNextPop)
            {
                break;
            }

            pTempPush++;
            stackData.push(*pTempPush);
        }

        // 该分支进入说明压入元素全部压入还未找到出栈元素
        if (stackData.top() != *pNextPop)
        {
            break;
        }

        stackData.pop();
        pNextPop++;
    }

    if (stackData.empty() && pNextPop - pPop == nLength)
    {
        bPossible = true;
    }

    return bPossible;
}
