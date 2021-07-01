#include "header.h"

int longestValidParentheses_r(string s)
{
    int max_len = 0;
    int i = 0;
    while ( i < s.length())
    {
        // Only check the phase that starts with '('.
        if (s[i] != '(')
        {
            ++i;
            continue;
        }

        int count = 1;
        int j = i + 1;
        while (j < s.length())
        {
            if (s[j] == '(')
            {
                ++count;
            }
            else
            {
                --count;
                if (count == 0)
                {
                    // a phase of parenthesis
                    max_len = max(max_len, j - i + 1);
                }
                else if (count < 0)
                {
                    // There are "more ')' than '(' between i and j.
                    break;
                }
            }
            ++j;
        }

        if (j < s.length())
        {
            // If there are "more ')' than '(' between i and j.
            // There is no need to check any string start in between.
            i = j + 1;
        }
        else
        {
            ++i;
        }
    }

    return max_len;
}