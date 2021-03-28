#include "header.h"

static string multiplySingle(string num1, char c);
static string add(string num1, string num2);

// xyz*mn = xyz*m0 + xyz*n;
// calculate xyzn in a function that takes single-digit multiplier
// xyz*m0 = xyz*m and shift left one position(add a char '0');
// Add each factor.
// Performance is not good. faster than 50%.
string multiply2(string num1, string num2)
{
    if (num1.empty() || num2.empty())
    {
        return "";
    }

    if (num1[0] == '0' || num2[0] == '0')
    {
        return "0";
    }

    string result;
    for (int i = num1.length() - 1; i >= 0; i--)
    {
        char c = num1[i];

        // Calculate num1[i]*num2.
        string temp = multiplySingle(num2, c);

        // Shift left accordingly
        for (int j = (num1.length() - 1 - i); j > 0; j--)
        {
            temp += '0';
        }

        // Add each factor. 
        result = add(result, temp);

    }

    return result;
}

// Allocate space for result first, then fill in each digit
string multiplySingle(string num1, char c)
{
    if (num1.empty())
    {
        return "";
    }
    else if (c == '0' || num1 == "0")
    {
        return "0";
    }

    int adv = 0;
    vector<char> mul(num1.length() + 1, '0');

    int i = num1.length() - 1;
    int k = mul.size() - 1;
    for (; i >= 0; i--, k--)
    {
        int d1 = (num1[i] - '0');
        int m = d1 * (c - '0');
        mul[k] = ((m + adv) % 10) + '0';
        adv = (m+ adv)/10;
    }

    if (adv > 0)
    {
        mul[k] = (adv + '0');
    }

    string result;
    for (int i = 0; i < mul.size(); i++)
    {
        // Skip prefixing '0'
        if (mul[i] != '0')
        {
            result.assign(mul.begin() + i, mul.end());
            break;
        }

    }

    return result;
}

// Allocate space for result first, then fill in each digit
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

    int sum_len = max(num1.length(), num2.length());

    vector<char> sum(sum_len + 1, '0');

    int adv = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int k = sum.size() - 1;
    for (; i >= 0 || j >= 0; i--, j--, k--)
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

        int ds = d1 + d2;
        sum[k] = (ds + adv) % 10 + '0';

        adv = (ds + adv)/10;
    }

    if (adv > 0)
    {
        sum[k] = (adv + '0');
    }

    string result;
    for (int i = 0; i < sum.size(); i++)
    {
        if (sum[i] != '0')
        {
            result.assign(sum.begin() + i, sum.end());
            break;
        }

    }

    return result;
}