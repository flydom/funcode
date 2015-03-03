/*
  两个排序数组A1和A2，A1末位有足够空间容纳A2。
  实现一个函数，将A2所有数字插入到A1并且所有数字均排序。
*/ 

#include "stdio.h"
#include "tchar.h"

void MergeArray(int Aarray[], int Barray[], int Alen, int Blen)
{
	if (NULL == Aarray || NULL == Barray || Alen < 0 || Blen < 0)
	{
		return;
	}
	
	// 提前跟面试官说好不考虑A/B数组长度之和溢出问题
	int AIndex = Alen - 1;
	int BIndex = Blen - 1;
	int MergeIndex = Alen + Blen - 1;
	for (; MergeIndex >= 0; MergeIndex--)
	{
		// B数组已全部插入
		if (BIndex < 0)
		{
			break;
		}
		
		// A数组全部比完
		if (AIndex < 0)
		{
			Aarray[MergeIndex] = Barray[BIndex--];
			continue;
		}
	
		if (Aarray[AIndex] >= Barray[BIndex])
		{
			Aarray[MergeIndex] = Aarray[AIndex--];
		}
		else
		{
			Aarray[MergeIndex] = Barray[BIndex--];
		}
	}
	
	return;
}