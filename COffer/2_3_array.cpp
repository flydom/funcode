#include <stdio.h>
#include <tchar.h> // ������stdafx.h�У���ͷ�ļ���Ԥ����ͷ�ļ�

#if 0
// �����Ͻǿ���
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
		// ԭ������ʹ�ô��β�**matrix��������ʹ��matrix[temp_row][temp_col]��ʽ
		// ����ͨ��������ִ�б��δ���������ΪC++�ж�ά�����޷��Զ�Ѱַ����Ҫ
		// �ֶ�����Ѱַ��ʽ.
		// eg. matrix[1] = matrix[0] + columns; ֮����ܷ���matrix[1][0]
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
// �����½ǿ���
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


// ====================���Դ���====================
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
// Ҫ���ҵ�����������
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
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