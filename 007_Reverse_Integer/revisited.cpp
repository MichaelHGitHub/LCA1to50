#include "header.h"

//int max = 0x7FFFFFFF(2147483647);
//int min = 0x80000000(-2147483648);

int reverse_r(int x)
{
    int result = 0;
    bool negative = x < 0;

    while (x)
    {
        if ((negative && (INT32_MIN / 10 < result || (INT32_MIN / 10 == result && (x % 10) >= -8))) ||
            (!negative && (INT32_MAX / 10 > result || (INT32_MAX / 10 == result && (x % 10) <= 7))))
        {
            result = result * 10 + (x % 10);
        }
        else
        {
            return 0;
        }
        x /= 10;
    }
    return result;
}


