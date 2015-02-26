#include <stdio.h>
#include <tchar.h> // 包含在stdafx.h中，该头文件是预编译头文件

#if 0
// 从右上角考虑
bool FindNum(int *matrix, int rows, int columns, int num)
{
	bool found = false;

	if (NULL == matrix || rows < 0 || columns < 0)
	{
		return false;
	}
	
	int temp_row = 0;
	int temp_col = columns - 1;
	
	while (temp_row < rows && temp_col >= 0)
	{
		// 原本尝试使用传形参**matrix，这里再使用matrix[temp_row][temp_col]形式
		// 编译通过，但是执行报段错误，这是因为C++中二维数组无法自动寻址，需要
		// 手动设置寻址方式.
		// eg. matrix[1] = matrix[0] + columns; 之后才能访问matrix[1][0]
		if (num == matrix[temp_row * columns + temp_col])
		{
			found = true;
			break;
		}
		else if (num > matrix[temp_row * columns + temp_col])
		{
			temp_row++;
		}
		else
		{
			temp_col--;
		}
	}
	
	return found;
}
#endif

#if 1
// 从左下角考虑
bool FindNum(int *matrix, int rows, int columns, int num)
{
	bool found = false;

	if (NULL == matrix || rows < 0 || columns < 0)
	{
		return false;
	}
	
	int temp_row = rows - 1;
	int temp_col = 0;
	
	while (temp_col < columns && temp_row >= 0)
	{
		if (num == matrix[temp_row * columns + temp_col])
		{
			found = true;
			break;
		}
		else if (num > matrix[temp_row * columns + temp_col])
		{
			temp_col++;
		}
		else
		{
			temp_row--;
		}
	}
	
	return found;
}
#endif


// ====================测试代码====================
void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    bool result = FindNum(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7()
{
    Test("Test7", NULL, 0, 0, 16, false);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}