#include <map>
#include "header.h"

// In a brute force way, we could do: x*x*x....x, but this would be too
// many iteration and performance would be too bad.
// To reduce interation, we can do (x)*(x^2)*(x^4)*(x^8)....(x^k) 
// while (1+2+4+8+...+k = n). We can have a seed starting from 1. 
// In each iteration, multiply seed by 2, then check if current 
// exponet number is larger than n. If yes, reset seed to 1 and repeat
// doing the above.
// Use a map to store the pair of (exponet, power) so that we can find 
// the corresponding power to use later. 
// Special case:
// 1. x = 0;
// 2. n = 0;
// 3  n = INT32_MIN(abs(INT32_MIN) is INT32_MIN, which we can handle;
double myPow(double x, int n)
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
            else if (n < 0)
            {
                an = abs(n);
            }

            int exponet = 1;
            double result = n > 0 ? x : (1.0000 / x);

            map<int, double> pows;
            pows[exponet] = result;
            int seed = 1;

            while(exponet < an)
            {
                // if the seed has grown too big, reset it to 1
                if (exponet > an - seed)
                {
                    seed = 1;
                }
                exponet += seed;
                result = result * pows[seed];
                // Save (exponet, power) for later use
                pows[exponet] = result;

                // Grow the seed by multipling 2
                seed *= 2;
            }

            // Remember to multiple 1/x if n is INT32_MIN
            if (INT32_MIN == n)
            {
                result *= (1.0000/x);
            }
            return result;
        }
    }
}