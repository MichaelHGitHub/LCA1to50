#include "header.h"

// If n % 2 = 0, x^n = x^(n/2) * x^(n/2), otherwise
// x^n = x * x^(n-1). Recursively call this function
// will get the final result.
// Special case:
// 1. x = 0;
// 2. n = 0;
// 3  n = INT32_MIN(abs(INT32_MIN) is INT32_MIN, which we can handle;
double myPow2(double x, int n)
{
    if (0.0000 == x)
    {
        return 0.0000;
    }
    else
    {
        if (0 == n)
        {
            return 1.0000;
        }
        else
        {
            int an = n;
            // abs(INT32_MIN) is INT32_MIN, we have to handle it in a
            // special way (x^(INT32_MAX+1))
            if (INT32_MIN == n)
            {
                an = INT32_MAX;
            }
            else
            {
                an = abs(n);
            }

            double px = (n > 0) ? x : (1.0000 / x);

            double result = 1.0000;
            if (an % 2 == 0)
            {
                double half = myPow2(px, an / 2);
                result = half * half;
            }
            else
            {
                double pre = myPow2(px, an-1);
                result = px * pre;
            }

            // Remember to multiple 1/x if n is INT32_MIN
            if (INT32_MIN == n)
            {
                result *= (1.0000 / x);
            }
            return result;
        }
    }
}