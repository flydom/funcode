/*
  替换空格。实现一个函数，将字符串中每个空格替换成“%20”
*/ 

#include "stdio.h"
#include "string.h"
#include "tchar.h"

 void ReplaceBlank(char *str, int length) // strlen为总长度
 {
	if (NULL == str || length < 0)
	{
		return;
	}
	
	int orignal_len =  strlen(str) + 1; // 有效字符长度
	int blank_cnt = 0;
	char *temp_str = str;
	
	while (*temp_str != '\0')
	{
		if (*temp_str == ' ')
		{
			blank_cnt++;
		}
		
		temp_str++;
	}
	
	int changed_len = orignal_len + 2 * blank_cnt; // ‘ ’替换成‘%20’，替换一次增加2
	if (changed_len > length)
	{
		return;
	}
	
	char *p1 = str + orignal_len - 1;
	char *p2 = str + changed_len - 1;
	while (p1 != p2)
	{
		if (*p1 != ' ')
		{
			*p2-- = *p1;
		}
		else
		{
			*p2-- = '0';
			*p2-- = '2';
			*p2-- = '%';		
		}
		
		p1--;
	}
	
	return;
 }
 
 // ================================================================
 
void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        printf("passed.\n");
    else if(expected == NULL && string != NULL)
        printf("failed.\n");
    else if(strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
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
    Test8();
    Test9();

    return 0;
}

