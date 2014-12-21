/*
 * TDD��������������Ϸ
 * �����������̣�http://blog.csdn.net/fzy0201/article/details/39805031
 *
 * Author: BigFun
 * Date  : 2014/12/21
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _context
{
	const char *s;
	int pos;
}Context;

int Record[10];

bool Is_STRIKE(int score)
{
	return score == 10;
}

int ParseScore(Context &ctx, int offset)
{
	int temp_score = 0;

	if (ctx.s[ctx.pos] == ' ')
	{
		ctx.pos++;
	}

	return atoi(ctx.s + ctx.pos + offset);
}

int CalcScorePerRound(Context &ctx)
{
	int offset = 0;
	int curr_score = 0;
	int next_score = 0;
	int round_score = 0;

	curr_score = ParseScore(ctx, 0);       // 0��ʾ������������ʼƫ��
	if (Is_STRIKE(curr_score))
	{
		offset = 2;
		next_score = ParseScore(ctx, offset);
		ctx.pos += 2;         // ����STRIKE����һ�ֻ���ʼ������λ��
	}
	else
	{
		offset = 0;
		ctx.pos++;
		next_score = ParseScore(ctx, offset);
		ctx.pos++;             // ����SPARE����һ�ֻ���ʼ������λ��
	}

	// ���ּƷ�
	if (10 > (curr_score + next_score))          // �������λ���δȫ��
	{	
		round_score = curr_score + next_score;
	}
	else                                       // ����STRIKE�����β���
	{
		int third_score = ParseScore(ctx, offset);
		round_score = curr_score + next_score + third_score;
	}

	return round_score;
}

int CalcScore(const char *s)
{
	Context ctx = {s, 0};
	int total_score = 0;

	printf("ÿ�ֵ÷֣�\n");
	for (int i = 0; i < 10; i++)
	{
		Record[i] = CalcScorePerRound(ctx);
		printf("%-2d ", Record[i]);
		total_score += Record[i];
	}
	printf("\n�ۼ��ܷ֣�%d", total_score);
	printf("\n+++++++++++++++++++++++++++++++++\n");

	return total_score;
}
