#include "header.h"

// Brute primitive solution: no shifting.
// Handle boundery carefully.
// Handle divisor = 1 or -1 to seed up so that get accepted by leetcode.
int divide2(int dividend, int divisor)
{
    int result = 0;

    if (divisor == INT32_MIN)
    {
        if (dividend == INT32_MIN)
        {
            return 1;
        }
        else
        {
            // All other dvidend is larger than divisor, return 0;
            return 0;
        }
    }
    else if (divisor == 0)
    {
        return INT32_MAX;
    }
    else if (divisor == 1)
    {
        return dividend;
    }
    else if (divisor == -1)
    {
        if (dividend == INT32_MIN)
        {
            return INT32_MAX;
        }
        else
        {
            return -dividend;
        }
    }

    bool is_ngative = false;

    if ((0 < dividend && 0 > divisor) || (0 > dividend && 0 < divisor))
    {
        is_ngative = true;
    }

    // Handle first divisor so that ads(dividend) won't over flow later
    int remaining = dividend;
    if (dividend == INT32_MIN)
    {
        if (is_ngative)
        {
            remaining = dividend + divisor;
            result--;
        }
        else
        {
            remaining = dividend - divisor;
            result++;
        }
    }

    // After above processing, abs() won't overflow
    int a_remaining = abs(remaining);
    int a_divisor = abs(divisor);

    while ((a_remaining -= a_divisor) >= 0)
    {
        if (is_ngative)
        {
            if(result > INT32_MIN)
            {
                result--;
            }
            else
            {
                return INT32_MAX;
            }
            
        }
        else
        {
            if (result < INT32_MAX)
            {
                result++;
            }
            else
            {
                return INT32_MAX;
            }
        }
    }

    return result;
}