/*
  替换空格。实现一个函数，将字符串中每个空格替换成“%20”
*/ 

#include "stdio.h"
#include "tchar.h"

 void ReplaceBlank(char *str, int strlen) // strlen为总长度
 {
	if (NULL == str || strlen < 0)
	{
		return;
	}
	
	int blank_cnt = 0;
	int orignal_len = strlen(str) +１；// 有效字符长度
	char temp_str = str;
	
	while (*temp_str != '/0’)
	{
		if (*temp_str == ' ')
		{
			blank_cnt++;
		}
		
		str++;
	}
	
	int changed_len = orignal_len + 2 * blank_cnt; // ‘ ’替换成‘%20’，替换一次增加2
	if (changed_len > strlen)
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