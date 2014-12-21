#include <assert.h>

extern int expr(const char *);

/* 演练遗留
extern int expr_addsub(const char *);
extern int expr_muldiv(const char *);
extern int expr_bracket_addsub(const char *);
extern int expr_bracket_muldiv(const char *);
*/

void main()
{
	// 可以给每一类测例单独封装一个测试类功能接口
	// test_pares_num
	assert(expr("1") == 1);
	assert(expr("2") == 2);

	// test_addsub
	assert(expr("1+2") == 3);
	assert(expr("2+3+4") == 9);
	assert(expr("2+3-4") == 1);

	// test_muldiv
	assert(expr("1") == 1);
	assert(expr("4*5") == 20);
	assert(expr("4*5*6") == 120);
	assert(expr("4*5/2") == 10);

	// test_mix
	assert(expr("2+4/2") == 4);
	assert(expr("2+4/2") == 4);
	assert(expr("1+2+3*4") == 15);
	assert(expr("2*3+4/2") == 8);

	// test_mix_bracket
	assert(expr("(1)") == 1);
	assert(expr("(1+1)") == 2);
	assert(expr("((2+3)-4)") == 1);
	assert(expr("(2+3)-(4-2)") == 3);
	assert(expr("(2+3)*(4/2)") == 10);
	
	// pow
	assert(expr("2^3") == 8);
	assert(expr("2^(8-3)^3") == 32768);
	assert(expr("2^(6*4/3)") == 256);
}