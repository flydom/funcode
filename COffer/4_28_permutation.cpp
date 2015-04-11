// 字符串排列

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void PermutationCore(char* pStr, char* pBegin)
{
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
        return;
    }

    for (char *c = pBegin; *c != '\0'; c++)
    {
        swap(c, pBegin); // 交换第一个与后续每一个字符，并固定住第一个字符

        PermutationCore(pStr, pBegin + 1); // pStr用来打印整个排列后的字符串

        swap(c, pBegin); // 每固定住第一个字符排列完后再换回原序列
    }
}

void Permutation(char* pStr)
{
    if (pStr == NULL )
    {
        return;
    }

    PermutationCore(pStr, pStr);
}

