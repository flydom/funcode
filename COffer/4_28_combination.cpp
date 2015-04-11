// 求字符的组合

void CombinationCore(char *pComBuff, char *pBegin, unsigned int m)
{
    if (*pBegin == '\0' && m != 0)
    {
        return;
    }

    if (m == 0)
    {
        printf("%s\n", pComBuff);
        return;
    }

    // 包含第一个字符，在剩下的求m-1个字符的组合
    pComBuff[m - 1] = *pBegin;
    CombinationCore(pComBuff, (pBegin + 1), (m - 1)); 

    // 不包含第一个字符，在剩下的求m个字符的组合
    CombinationCore(pComBuff, (pBegin + 1), m);
}

void Combination(char* pStr)
{
    if (pStr == NULL)
    {
        return;
    }

    unsigned int len = strlen(pStr);
    char *pComBuff = new char[len + 1];
    memset(pComBuff, 0, len + 1);
    
    for (unsigned int m = 1; m <= len; m++)
    {
        CombinationCore(pComBuff, pStr, m);
    }

    delete[] pComBuff;
}