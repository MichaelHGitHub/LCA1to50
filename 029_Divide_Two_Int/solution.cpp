#include "header.h"

// I call this solution Binary Division, this idea is:
// X/Y = (X1 + X2+..+Xn)/Y, assuming X1 = Y*2^a, X2 = Y*2^b, ... X(n-1)= Y*2^z, Xn < Y.
// therefore X/Y = (2^(a+b+...+z)) + Xn/Y. As Xn < Y, it will be ignored in the quoutient. 
// In the factor 2^a*Y, the way to calculate a is:
// 1)Try if 2Y > X, if not, try 2^2*Y, if not, try 2^3*Y, goes on and on until 2^(a+1)*Y>X.
// 2)Make X = X-2^a*Y, and repeat step 1 to calulate b and others, until X(remain)<Y.
// This can be implemented in recurrsive and non-recurrsive way.
// Special case:
// 1. divisor = INT32_MIN
// 2. divisor = 0
// 3. dividend = INT32_MIN

int divide(int dividend, int divisor)
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

    // The n-th power of 2
    int nth_pow_2 = 1;
    // Initial factor is a_divisor(2^0*Y)
    int factor = a_divisor;

    while (true)
    {
        if (factor > a_remaining)
        {
            break;
        }

        // Need to make sure 2*factor not overflow
        if (factor <= a_remaining - factor)
        {
            nth_pow_2 <<= 1;
            factor <<= 1;
        }
        else if (factor <= a_remaining)
        {
            // Deduct factor from a_remaining for the calculation of next factor
            a_remaining = a_remaining - factor;
            // factor is reset to a_divisor(2^0*Y)
            factor = a_divisor;

            if (is_ngative)
            {
                // Make sure result not overflow
                if (result >= (INT32_MIN + nth_pow_2))
                {
                    result -= nth_pow_2;
                }
                else
                {
                    return INT32_MAX;
                }
            }
            else
            {
                // Make sure result not overflow
                if (result <= (INT32_MAX - nth_pow_2))
                {
                    result += nth_pow_2;
                }
                else
                {
                    return INT32_MAX;
                }
            }

            // Reset n-th power of 2 to 2^0 for next factor
            nth_pow_2 = 1;
        }
    }

    return result;
}