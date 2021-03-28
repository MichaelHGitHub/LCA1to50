#include "header.h"


string convertNumToRomanLetter2(int digit, int multiper)
{
    string result;
    int temp_num = digit * multiper;

    if (temp_num <= 5)
    {
        if (temp_num == 5)
        {
            result = "V";
        }
        else if (temp_num == 4)
        {
            result = "IV";
        }
        else
        {
            for (int i = temp_num / multiper; i > 0; i--)
            {
                result += "I";
            }
        }
    }
    else if (temp_num <= 10)
    {
        if (temp_num == 10)
        {
            result = "X";
        }
        else if (temp_num == 9)
        {
            result = "IX";
        }
        else
        {
            if (temp_num >= 5)
            {
                result = "V";
                temp_num -= 5;
            }

            for (int i = temp_num / multiper; i > 0; i--)
            {
                result += "I";
            }
        }
    }
    else if (temp_num <= 50)
    {
        if (temp_num == 50)
        {
            result = "L";
        }
        else if (temp_num == 40)
        {
            result = "XL";
        }
        else
        {
            for (int i = temp_num / multiper; i > 0; i--)
            {
                result += "X";
            }
        }
    }
    else if (temp_num <= 100)
    {
        if (temp_num == 100)
        {
            result = "C";
        }
        else if (temp_num == 90)
        {
            result = "XC";
        }
        else
        {
            if (temp_num >= 50)
            {
                result = "L";
                temp_num -= 50;
            }

            for (int i = temp_num / multiper; i > 0; i--)
            {
                result += "X";
            }
        }
    }
    else if (temp_num <= 500)
    {
        if (temp_num == 500)
        {
            result = "D";
        }
        else if (temp_num == 400)
        {
            result = "CD";
        }
        else
        {
            for (int i = temp_num / multiper; i > 0; i--)
            {
                result += "C";
            }
        }

    }
    else if (temp_num <= 1000)
    {
        if (temp_num == 1000)
        {
            result = "M";
        }
        else if (temp_num == 900)
        {
            result = "CM";
        }
        else
        {
            if (temp_num >= 500)
            {
                result = "D";
                temp_num -= 500;
            }

            for (int i = temp_num / multiper; i > 0; i--)
            {
                result += "C";
            }
        }
    }
    else
    {
        // num can't be larger than 3
        for (int i = temp_num / multiper; i > 0; i--)
        {
            result += "M";
        }
    }

    return result;

}