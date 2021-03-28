#include "header.h"

int myCtoi(char c)
{
    int diff = (c - '0');
    if (0 <= diff && diff <= 9)
    {
        return diff;
    }
    else
    {
        return -1;
    }
}

bool myAtoiCore(int* result, char c, bool isNagtive)
{
    bool keep_going = true;
    int digit = myCtoi(c);

    if (digit != -1)
    {
        if (isNagtive)
        {
            digit *= -1;
        }

        // check if beyond the upper boundery
        // if the value is larger than INT32_MAX / 10 ,
        // value * 10 will definitely larger than INT32_MAX
        // if value equals to INT32_MAX / 10, in order to make 
        // value*10 + last-digit <= INT32_MAX, last-digit must <= 7. 
        // INT32_MAX - (INT32_MAX/10)*10 = 7;
        if ((*result > INT32_MAX / 10) || (*result == INT32_MAX / 10 && digit > 7))
        {
            *result = INT32_MAX;
            keep_going = false;
        }

        // check if beyond the lower boundery, same idea as Max value. 
        // just the last-digit must >= -8.
        if ((*result < INT32_MIN / 10) || (*result == INT32_MIN / 10 && digit < -8))
        {
            *result = INT32_MIN;
            keep_going = false;
        }

        if (keep_going)
        {
            *result = *result * 10 + digit;
        }
    }
    else
    {
        keep_going = false;
    }

    return keep_going;
}

int myAtoi(string s) {

    bool is_nagtive = false;

    // Need to know if all blank charecter so far
    bool all_blank = true;
    int result = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
        {
            if (all_blank)
            {
                // Ignore the starting blank space(trim).
                continue;
            }
            else
            {
                // blank sapce appears in the in the mid of the string
                // stop proceeding.
                break;
            }
        }
        else if (s.at(i) == '+')
        {
            if (all_blank)
            {
                // "+" is the first valid charecter.
                all_blank = false;
                continue;
            }
            else
            {
                // "+" appears in the mid of string, stop proceeding
                all_blank = false;
                break;
            }
        }
        else if (s.at(i) == '-')
        {
            if (all_blank)
            {
                // "-" is the first valid charecter.
                all_blank = false;
                is_nagtive = true;
                continue;
            }
            else
            {
                // "+" appears in the mid of string, stop proceeding
                all_blank = false;
                break;
            }
        }
        else
        {
            // digits start to appear
            all_blank = false;

            if (myAtoiCore(&result, s.at(i), is_nagtive) == false)
            {
                break;
            }
        }
    }

    return result;
}