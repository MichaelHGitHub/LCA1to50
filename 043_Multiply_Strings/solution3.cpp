#include "header.h"

//Allocate space for result, save the number at each postion as int
// in an array, build the string after all the numbers are ready.
string multiply3(string num1, string num2)
{
    vector<int> numbers(num1.length() + num2.length(), 0);

    for (int i = num1.length() - 1; i >= 0; i--)
    {
        for (int j = num2.length() - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');

            // Here remember to add the old number first to handle
            // a possible old carray up that was not handled in 
            // previous interation.
            int sum = numbers[i + j + 1] + mul;
            int dig = sum % 10;
            int adv = sum / 10;

            // numbers[i + j + 1] is ready
            numbers[i + j + 1] = dig;
            // numbers[i + j] may still need a continus carry up, 
            // it will be handled in next iteration. 
            numbers[i + j] += adv;
        }
    }

    string result;
    int i = 0;

    // Skip prefixing '0'
    for ( ;i < numbers.size(); i++)
    {
        if (numbers[i] != 0)
        {
            break;
        }

    }

    // Build the string
    for (; i < numbers.size(); i++)
    {
        result.push_back(numbers[i] + '0');
    }

    // Handle empty string
    if (result.empty())
    {
        result = "0";
    }

    return result;
}