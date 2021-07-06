#include "header.h"

string multiply_r(string num1, string num2)
{
    int size = num1.size() + num2.size();
    vector<int> product(size, 0);

    for (int i = num2.size() - 1; i >= 0; i--)
    {
        for (int j = num1.size() - 1; j >= 0; j--)
        {
            int pos = i + j + 1;
            int sum = product[pos] + (num2[i] - '0') * (num1[j] - '0');
            product[pos] = (sum % 10);

            int carry_on = sum / 10;
            int offset = 1;

            while (carry_on)
            {
                sum = product[pos - offset] + carry_on;
                product[pos - offset] = (sum % 10);
                carry_on = sum / 10;
                ++offset;
            }
        }
    }

    bool leading_zero = true;
    string result;

    for (int i : product)
    {
        if (leading_zero && i == 0)
        {
            continue;
        }
        else
        {
            leading_zero = false;
            result.push_back(i + '0');
        }
    }
    
    return leading_zero ? "0" : result;

}