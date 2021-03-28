#include "header.h"

// No recursive solution
// First loop is given number from 2 to n(1 is base)
// Second loop: scan the previous string and build the current count and say.
// Special case: last char of each iteration. 
string countAndSay2(int n)
{
    if (1 == n)
    {
        return "1";
    }

    string result = "1";

    for (int i = 2; i <= n; i++)
    {
        char c = ' ';
        int count = 0;
        string temp = "";
        int j = 0;
        while (j < result.length())
        {
            if (c != result[j])
            {
                if (c != ' ')
                {
                    temp.push_back(count + '0');
                    temp.push_back(c);
                }

                c = result[j];
                count = 1;
                j++;
            }
            else
            {
                count++;
                j++;
            }
        }

        // the very last char(or chars) is(are) not handled yet, do it here
        if (j == result.length())
        {
            temp.push_back(count + '0');
            temp.push_back(c);
        }

        result = temp;
    }

    return result;
}