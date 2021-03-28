#include <map>
#include "header.h"



// This(map) is what leetcode suggest, but it is not as fast as my solution 
// which uses if and case.
int romanToInt2(string s)
{
    map<string, int> dictionary;
    dictionary["I"] = 1;
    dictionary["IV"] = 4;
    dictionary["V"] = 5;
    dictionary["IX"] = 9;
    dictionary["X"] = 10;
    dictionary["XL"] = 40;
    dictionary["L"] = 50;
    dictionary["XC"] = 90;
    dictionary["C"] = 100;
    dictionary["CD"] = 400;
    dictionary["D"] = 500;
    dictionary["CM"] = 900;
    dictionary["M"] = 1000;

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
            if (dictionary.find(s.substr(i - 1, 2)) != dictionary.end())
            {
                temp = dictionary[s.substr(i - 1, 2)];
            }
        }

        if (temp > 0)
        {
            // Find a combination of two letters, skip them before next round
            i -= 2;
        }
        else
        {
            // No two-letter combination found, try single letter
            if (dictionary.find(s.substr(i, 1)) != dictionary.end())
            {
                temp = dictionary[s.substr(i, 1)];
            }
            i--;
        }

        // Add the value for the current occurrence
        num += temp;
    }


    return num;
}
