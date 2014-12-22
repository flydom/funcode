#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

extern void CtxInit();
extern string Game(const int data);

void Test_Rule_1()
{
	assert("Cute" == Game(3));
	assert("Cute" == Game(66));

	assert("Da" == Game(5));
	assert("Da" == Game(200));

	assert("Evil" == Game(7));
	assert("Evil" == Game(707));
}

void Test_Rule_2()
{
	assert("CuteDa" == Game(15));
	assert("CuteDa" == Game(45));

	assert("DaEvil" == Game(70));
	assert("DaEvil" == Game(140));

	assert("CuteEvil" == Game(21));
	assert("CuteEvil" == Game(42));
}

void Test_Rule_3()
{
	assert("CuteDaEvil" == Game(105));
	assert("CuteDaEvil" == Game(210));
}

void Test_Rule_4()
{
	assert("Cute" == Game(35));
	assert("Cute" == Game(53));
	assert("Cute" == Game(375));
}

void main()
{
	CtxInit();

	Test_Rule_1();
	Test_Rule_2();
	Test_Rule_3();
	Test_Rule_4();

	getchar();
}
