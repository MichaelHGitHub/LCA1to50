#include "header.h"

static string countDigits(string digits);

string countAndSay_r(int n)
{
    string result = "1";

    for (int i = 2; i <= n; i++)
    {
        result = countDigits(result);
    }

    return result;
}

string countDigits(string digits)
{
    string result;
    int count = 0;
    char d = ' ';
    for (int i = 0; i < digits.length(); i++)
    {
        if (digits[i] == d)
        {
            ++count;
        }
        else
        {
            if (count != 0)
            {
                result += (to_string(count) + d);
            }
            count = 1;
            d = digits[i];
        }
    }
    result += (to_string(count) + d);

    return result;
}