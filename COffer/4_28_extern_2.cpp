// 八皇后问题

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool Func_Queue(int *array, int length)
{
    bool result = true;

    for (int x = 0; x < length && result; x++)
    {
        for (int y = x + 1; y < length; y++)
        {
            if ((x - y == array[x] - array[y]) ||
                (y - x == array[x] - array[y]))
            {
                result = false; 
                break;
            }
        }
    }

    return result;
}

void QueenCore(int *array, int length, int index, int &count)
{
    if (index >= length)
    {
        // TODO: 
        bool result = false;
        result = Func_Queue(array, length);
        if (result == true)
        {        
            count++;
            for (int m = 0; m < 8; m++)
            {
                printf("%d\t", array[m]);
            }
            printf("\n");
        }
        
        return;
    }
    
    for (int i = index; i < length; i++)
    {
        swap(&array[i], &array[index]);
    
        QueenCore(array, length, index + 1, count);

        swap(&array[i], &array[index]); 
    }
}


void QueenPro(int *array, int length, int &count)
{
    if (array == NULL || length <= 0)
    {
        return;
    }

    QueenCore(array, length, 0, count);
} 


// ====================测试代码====================
void Test(char *test, int *array, int length)
{
    static int count = 0;

    if(test == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", test);

    QueenPro(array, length, count);

    printf("Queen : %d\n", count);
}


int _tmain(int argc, _TCHAR* argv[])
{
    int array[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    Test("8_Queen", array, 8);

    return 0;
}