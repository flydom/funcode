// 数组中所有奇数在偶数前面，此题重在抽象
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// 方法一
void ReorderOddEven_1(int *pData, unsigned int length)
{
    if (pData == NULL || length <= 0)
    {
        return;
    }

    int *pBegin = pData;
    int *pEnd = pData + length -1;

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && (*pBegin & 0x1) != 0)
        {
            pBegin++;
        }

        while (pBegin < pEnd && (*pEnd & 0x1) == 0)
        {
            pEnd--;
        }

        if (pBegin < pEnd)
        {
            swap(pBegin, pEnd);
        }
    }
}

// 方法二
bool isEven(int n)
{
    return (n & 0x1) == 0;
}

void Reorder(int *pData, unsigned int length, bool (* func)(int))
{
    if (pData == NULL || length <= 0)
    {
        return;
    }

    int *pBegin = pData;
    int *pEnd = pData + length -1;

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && !func(*pBegin))
        {
            pBegin++;
        }

        while (pBegin < pEnd && func(*pEnd))
        {
            pEnd--;
        }

        if (pBegin < pEnd)
        {
            swap(pBegin, pEnd);
        }
    }
}

void ReorderOddEven_2(int *pData, unsigned int length)
{
    Reorder(pData,length, isEven);
}
