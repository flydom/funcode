// 逐一打印N位数
void PrintNumber(char* number)
{
    int nLen = strlen(number);
    for (int i = 0; i <= nLen - 1; i++)
    {
        if (number[i] == '0')
        {
            continue;
        }
        else
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}


bool Increment(char* number)
{
    bool IsOverflow = false;
    int nLen = strlen(number);
    int nCarrybit = 0;

    for (int i = nLen - 1; i >= 0; i--)
    {
        int Sum = number[i] - '0' + nCarrybit;
        if (i == nLen - 1)
        {
            Sum++;
        }

        if (Sum >= 10)
        {
            if (i == 0)
            {
                IsOverflow = true;
            }
            else
            {
                Sum -= 10;
                nCarrybit = 1;
                number[i] = Sum + '0';
            }
        }
        else
        {
            number[i] = Sum + '0';
            break;
        }
    }

    return IsOverflow;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits_1(int n)
{
    if (n <= 0)
    {
        printf("Input error!\n");
        return;
    }

    char *num = new char[n + 1];
    memset(num, '0', n);
    num[n] = '\0';

    while (!Increment(num))
    {
        PrintNumber(num);
    }

    delete[] num;
}

void Print1ToMaxOfNDigits_2(int n)
{
    if (n <= 0)
    {
        printf("Input error!\n");
        return;
    }

    char* number = new char[n + 1];
    number[n] = '\0';
 
    for(int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
 
    delete[] number;
}
