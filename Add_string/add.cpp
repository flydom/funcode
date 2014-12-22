/*
 * TDD演练：字符串相加
 * 代码演练过程：http://blog.csdn.net/fzy0201/article/details/40263499
 *
 * Author: BigFun
 * Date  : 2014/12/22
 */
#include <iostream>
#include <string>
using namespace std;

#define  NumToStr(x)  (x + '0') 

typedef unsigned int uint;

uint GetNum(const string &str, uint index)
{
	uint temp_value = 0;

	if (index < str.length())
	{
		temp_value = str[str.length() - 1 - index] - '0';
	}
	return temp_value;
}

string Add(const string &left, const string &right)
{
	uint carry_bit = 0;
	string result = left.size() >= right.size() ? left : right;

	for (uint i = 0; i < left.size() || i < right.size(); i++)
	{
		uint temp_value = GetNum(left, i) + GetNum(right, i) + carry_bit;

		carry_bit = temp_value / 10;

		temp_value = temp_value % 10;
		result[result.length() - 1 - i] = NumToStr(temp_value);
	}

	if (carry_bit > 0)
	{
		result.insert(result.begin(), NumToStr(carry_bit));
	}

	cout << ">:" <<  result << "\n";

	return result;
}