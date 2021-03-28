#include "header.h"

string intToRoman(int num)
{
    string letters;

    int temp_num = num;
    int multiplier = 1;

    while (temp_num)
    {
        // Process from the lowest digit
        int digit = temp_num % 10;

        string letters_of_digit = convertNumToRomanLetter(digit, multiplier);

        letters = letters_of_digit + letters;

        temp_num /= 10;
        multiplier *= 10;
    }

    return letters;
}

string convertNumToRomanLetter(int digit, int multiper)
{
    string result;
    int temp_num = digit * multiper;
    string to_be_appened = "";

    if (temp_num >= 1000)
    {
        to_be_appened = "M";
    }
    else if (temp_num == 900)
    {
        result = "CM";
        to_be_appened = "";
        temp_num -= 900;
    }
    else if (temp_num >= 500)
    {
        result = "D";
        to_be_appened = "C";
        temp_num -= 500;
    }
    else if (temp_num == 400)
    {
        result = "CD";
        to_be_appened = "";
        temp_num -= 400;
    }
    else if (temp_num >= 100)
    {
        to_be_appened = "C";
    }
    else if (temp_num == 90)
    {
        result = "XC";
        to_be_appened = "";
        temp_num -= 90;
    }
    else if (temp_num >= 50)
    {
        result = "L";
        to_be_appened = "X";
        temp_num -= 50;
    }
    else if (temp_num == 40)
    {
        result = "XL";
        to_be_appened = "";
        temp_num -= 40;
    }
    else if (temp_num >= 10)
    {
        to_be_appened = "X";
    }
    else if (temp_num == 9)
    {
        result = "IX";
        to_be_appened = "";
        temp_num -= 9;
    }
    else if (temp_num >= 5)
    {
        result = "V";
        to_be_appened = "I";
        temp_num -= 5;
    }
    else if (temp_num == 4)
    {
        result = "IV";
        to_be_appened = "";
        temp_num -= 4;
    }
    else
    {
        to_be_appened = "I";
    }

    if (temp_num > 0)
    {
        for (int i = temp_num / multiper; i > 0; i--)
        {
            result += to_be_appened;
        }
    }

    return result;

}