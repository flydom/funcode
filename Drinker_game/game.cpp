/*
 * TDD演练：酒令游戏
 * 代码演练过程：http://blog.csdn.net/fzy0201/article/details/40717655
 *
 * Author: BigFun
 * Date  : 2014/12/22
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Special_Words 
{
	int spcial_num;
	string words;
} Context;

vector <Context> Ctx;

void CtxInit()
{
	Context First = {3, "Cute"};
	Ctx.push_back(First);

	Context Second = {5, "Da"};
	Ctx.push_back(Second);

	Context Third = {7, "Evil"};
	Ctx.push_back(Third);
}

string Game(int data)
{
	string result;
	int temp = data;
	
	do
	{
		int first_num = temp % 10;
		if (first_num == Ctx.begin()->spcial_num)
		{
			result = Ctx.begin()->words;
			return result;
		}

		temp = temp / 10;
	} while (temp != 0);

	for (vector <Context>::iterator iter = Ctx.begin();
		 iter != Ctx.end(); ++iter)
	{
		if (0 == data % iter->spcial_num)
		{
			result += iter->words;
		}
	}

	return result;
}
