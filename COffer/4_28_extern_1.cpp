// 正方体三对面定点和是否相等

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


bool EqualCore(int array[8], int length, int index)
{
    bool result = false;
    if (index >= 8)
    {
        // TODO: 判断
        if ((array[0]+array[1]+array[2]+array[3] == array[4]+array[5]+array[6]+array[7]) &&
            (array[0]+array[2]+array[4]+array[6] == array[1]+array[3]+array[5]+array[7]) &&
            (array[0]+array[1]+array[4]+array[5] == array[2]+array[3]+array[6]+array[7]))
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d\t", array[j]);
            }
            printf("\n");
            
            result = true;
        }

        return result;
    }
    
    for (int i = index; i < length; i++)
    {
        swap(&array[i], &array[index]);
    
        result = EqualCore(array, length, index + 1);
        if (result == true)
        {
            break;
        }

        swap(&array[i], &array[index]); 
    }

    return result;
}


bool EqualCore(int *array, int length)
{
    if (array == NULL || length <= 0)
    {
        return false;
    }

    return EqualCore(array, length, 0);
} 


// ====================测试代码====================
void Test(char *test, int *array, int length)
{
    bool result = false;

    if(test == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", test);

    result = EqualCore(array, length);
    if (result == true)
    {
        printf("%s Success!\n", test);
    }
    else
    {
        printf("%s failed!\n", test);
    }

    printf("\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
    int array1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("test1", array1, 8);

    int array2[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    Test("test2", array2, 8);

    int array3[8] = {2, 2, 3, 1, 1, 3, 4, 4};
    Test("test3", array3, 8);


    return 0;
}