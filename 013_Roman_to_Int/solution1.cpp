#include "header.h"

int romanToInt(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }

    int num = 0;

    int i = s.length() - 1;

    while (i >= 0)
    {
        int temp = 0;

        if (i > 0)
        {
            // Try two letters first
            temp = handleDoubleLetters(s.substr(i - 1, 2));
        }

        if (temp > 0)
        {
            // Found a combination of two letters, skip them before next round
            i -= 2;
        }
        else
        {
            // No two-letter combination found, try single letter
            temp = handleSingleLetter(s.at(i));
            i--;
        }

        num += temp;
    }


    return num;
}

// If-else seems faster than a map
int handleDoubleLetters(string s)
{
    if (s == "IV")
    {
        return 4;
    }

    if (s == "IX")
    {
        return 9;
    }

    if (s == "XL")
    {
        return 40;
    }

    if (s == "XC")
    {
        return 90;
    }

    if (s == "CD")
    {
        return 400;
    }

    if (s == "CM")
    {
        return 900;
    }

    return 0;

}

// If-else seems faster than a map
int handleSingleLetter(char c)
{
    int num = 0;

    switch (c)
    {
    case 'I':
        num = 1;
        break;

    case 'V':
        num = 5;
        break;

    case 'X':
        num = 10;
        break;

    case 'L':
        num = 50;
        break;

    case 'C':
        num = 100;
        break;

    case 'D':
        num = 500;
        break;

    case 'M':
        num = 1000;
        break;

    default:
        num = 0;
    }

    return num;
}

