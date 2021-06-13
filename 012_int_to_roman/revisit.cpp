#include "header.h"

string intToRoman_r(int num)
{
    string result;

    if (num / 1000)
    {
        int c = num / 1000;
        for (int i = 0; i < c; i++)
        {
            result += "M";
        }
        num %= 1000;
    }

    if (num / 900)
    {
        result += "CM";
        num %= 900;
    }

    if (num / 500)
    {
        result += "D";
        num %= 500;
    }

    if (num / 400)
    {
        result += "CD";
        num %= 400;
    }

    if (num / 100)
    {
        int c = num / 100;
        for (int i = 0; i < c; i++)
        {
            result += "C";
        }
        num %= 100;
    }

    if (num / 90)
    {
        result += "XC";
        num %= 90;
    }

    if (num / 50)
    {
        result += "L";
        num %= 50;
    }

    if (num / 40)
    {
        result += "XL";
        num %= 40;
    }

    if (num / 10)
    {
        int c = num / 10;
        for (int i = 0; i < c; i++)
        {
            result += "X";
        }
        num %= 10;
    }

    if (num / 9)
    {
        result += "IX";
        num %= 9;
    }

    if (num / 5)
    {
        result += "V";
        num %= 5;
    }

    if (num / 4)
    {
        result += "IV";
        num %= 4;
    }

    if (num / 1)
    {
        int c = num;
        for (int i = 0; i < c; i++)
        {
            result += "I";
        }
    }

    return result;
}