#include <assert.h>
#include <string>
using namespace std;

extern string Add(const string &str1, const string &str2);

void No_Carrybit_Test()
{
	assert("3" == Add("1","2"));
}

void Single_Carrybit_Test()
{
	assert("10" == Add("1","9"));
	assert("11" == Add("2","9"));
}

void Multi_Carrybit_Test()
{
	assert("100" == Add("1","99"));
	assert("1000" == Add("1","999"));
}

void Complex_Operation_Test()
{
	assert("101" == Add("2","99"));
	assert("198" == Add("99","99"));
	assert("12444" == Add("12345","99"));
	assert("123456789123456789123457011" == Add("123456789123456789123456789", "222"));
}

void main()
{
	No_Carrybit_Test();

	Single_Carrybit_Test();

	Multi_Carrybit_Test();

	Complex_Operation_Test();

	getchar();
}
