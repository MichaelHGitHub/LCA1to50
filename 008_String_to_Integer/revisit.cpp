#include "header.h"


int myAtoi_r(string s)
{
    int result = 0;
    int sign = 0;

    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case ' ':
            if (sign != 0)
            {
                return result;
            }
            break;
        case '+':
            if (sign != 0)
            {
                return result;
            }
            else
            {
                sign = 1;
            }
            break;
        case '-':
            if (sign != 0)
            {
                return result;
            }
            else
            {
                sign = -1;
            }
            break;
        default:
            if (s[i] > '9' || s[i] < '0')
            {
                if (sign != 0)
                {
                    return result;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if (sign==0)
                {
                    sign = 1;
                }

                if (sign > 0)
                {
                    if (INT32_MAX / 10 > result || (INT32_MAX / 10 == result && s[i] - '0' <= 7))
                    {
                        result = result * 10 + (s[i] - '0');
                    }
                    else
                    {
                        return INT32_MAX;
                    }
                }
                else
                {
                    if (INT32_MIN / 10 < result || (INT32_MIN / 10 == result && s[i] - '0' <= 8))
                    {
                        // Do (s[i] - '0') first in case int overflow
                        result = result * 10 - (s[i] - '0');
                    }
                    else
                    {
                        return INT32_MIN;
                    }
                }
            }
        }
    }

    return result;
}