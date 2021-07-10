#include "header.h"

double myPow_r(double x, int n)
{
    double result = 1.00000;

    int seed = (n >= 0 ? 1 : -1);
    int i = 0;
    double ith_pow_of_x = (n >= 0 ? x : 1/x);

    while ((n >= 0 && i < n) || (n < 0 && i > n))
    {
        i += seed;
        result *= ith_pow_of_x;

        // If seed grows too big(or small in negative), reset it.
        if ((n >= 0 && (seed > (n - i) / 2)) || (n < 0 && (seed < (n - i) / 2)))
        {
            seed = (n >= 0 ? 1 : -1);
            ith_pow_of_x = (n >= 0 ? x : 1 / x);
        }
        else
        {
            seed *= 2;
            ith_pow_of_x *= ith_pow_of_x;
        }
    }

    return result;
}