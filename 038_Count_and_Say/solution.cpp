#include "header.h"

// Recursive solution
// First: get the previous string.
// Second: scan the previous string and build the current one.
// Special case: last char of each iteration. 
string countAndSay(int n)
{
    if (1 == n)
    {
        return "1";
    }

    string pre = countAndSay(n - 1);

    char c = ' ';
    int count = 0;
    string result = "";
    int i = 0;
    while(i < pre.length())
    {
        if (c == pre[i])
        {
            count++;
        }
        else
        {
            if (c != ' ')
            {
                // use string::push_back instead of += to help with performance.
                // the ascII code of count is (count + '0').
                result.push_back(count + '0');
                result.push_back(c);
            }

            c = pre[i];
            count = 1;
        }

        i++;
    }

    // the very last char(or chars) is(are) not handled yet, do it here
    if (i == pre.length())
    {
        result.push_back(count + '0');
        result.push_back(c);
    }

    return result;
}