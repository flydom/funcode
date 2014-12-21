#include <assert.h>

extern int CalcScore(const char *s);

void main()
{
	assert(CalcScore("10 10 10 10 10 10 10 10 10 10 10 10") == 300);
	assert(CalcScore("10 10 10 7 2 9 1 8 1 8 2 10 9 1 10 8 2") == 192);
	assert(CalcScore("1 4 4 5 6 4 5 5 10 0 1 7 3 6 4 10 2 8 6") == 133);
}