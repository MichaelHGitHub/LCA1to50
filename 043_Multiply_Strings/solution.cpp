#include "header.h"

string add(string num1, string num2);

// 123 * 35 = 123*30 + 123*5;
// Convert multiply to addition, calculate 123*5
// 123*30 = 123*3 and shift left(add a char '0');
// Add each factor. 
// Performance is not good. faster than 10%.
string multiply(string num1, string num2)
{
    if (num1.empty() || num2.empty())
    {
        return "";
    }

    if (num1[0 ]== '0' || num2[0] == '0')
    {
        return "0";
    }

    string result;
    for (int i = num1.length() - 1; i >= 0; i--)
    {
        string temp;

        char d = num1[i];
        // for each digit in num1, add nums. equals to num1[i]*num2
        for (; d > '0'; d--)
        {
            temp = add(temp, num2);
        }

        // Shift left accordingly.
        for (int j = (num1.length() - 1 - i); j > 0; j--)
        {
            temp += '0';
        }

        // Add each factor
        result = add(result, temp);

    }

    return result;
}

// Brute force, build each digit
string add(string num1, string num2)
{
    if (num1.empty())
    {
        return num2;
    }
    else if (num2.empty())
    {
        return num1;
    }

    int adv = 0;
    string sum;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    for (; i >= 0 || j >= 0; i--, j--)
    {
        int d1 = 0;
        int d2 = 0;

        if (i >= 0)
        {
            d1 = (num1[i] - '0');
        }

        if (j >= 0)
        {
            d2 = (num2[j] - '0');
        }

        // Handle carry up
        int ds = d1 + d2;
        sum.insert(sum.begin(), ((ds + adv) % 10 +'0'));

        adv = ((ds + adv > 9) ? 1 : 0);
    }

    // Don't forget the last carry up.
    if (adv > 0)
    {
        sum.insert(sum.begin(), (adv + '0'));
    }

    return sum;
}