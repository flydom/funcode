// 顺时钟打印矩阵

void printNumber(int number)
{
    printf("%d\t", number);
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
    int endX = rows - 1 - start;
    int endY = columns - 1 - start;

    int i = start;
    // 从左到右打印一行
    for (; i <= endY; i++)
    {
        printNumber(numbers[start][i]);
    }

    // 从上到下打印一列
    if (start < endX)
    {
        for (i = start + 1; i <= endX; i++)
        {
            printNumber(numbers[i][endY]);
        }
    }

    // 从右到左打印一行
    if (start < endX && start < endY)
    {
        for (i = endY - 1; i >= start; i--)
        {
            printNumber(numbers[endX][i]);
        }
    }
    
    // 从下到上打印一行
    if (start + 1 < endX && start < endY)
    {
        for (i = endX; i >= start + 1; i--)
        {
            printNumber(numbers[i][start]);
        }
    }

}

void PrintMatrixClockwisely(int** numbers, int rows, int columns)
{
    if (numbers == NULL || columns < 0 || rows < 0)
    {
        return;
    }

    int start = 0;

    while (rows > 2 * start && columns > 2 * start)
    {
        PrintMatrixInCircle(numbers, rows, columns, start);

        start++;
    }
}
