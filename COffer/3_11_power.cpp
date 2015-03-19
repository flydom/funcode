// 求数的幂

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.00000001) && 
        (num1 - num2 < 0.00000001))
    {
        return true;
    }

    return false;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;

/* 1) 
    for (unsigned int i = 0; i < exponent; i++ )
    {
        result *= base;
    }
*/

/* 2) */

    if (exponent == 0)
    {
        return 1.0;
    }

    if (exponent == 1)
    {
        return base;
    }

    result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x01) // 判断exponent为奇数
    {
        result = result * base; 
    }

    return result;
}



double Power(double base, int exponent)
{
    double result = 1.0;

    if (equal(base, 0.0) == true && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)exponent; 
    if (exponent < 0)
    {
        absExponent = (unsigned int)(-exponent);
    }

    // 1):
    //    result = PowerWithUnsignedExponent(base, absExponent);
    // 2):
    result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
    {
        result = 1.0 / result;
    }

    return result;
}
