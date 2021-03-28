#include "header.h"

int longestValidParentheses2(string s)
{
    int longest_number = 0;

    int i = 0;
    while (i < s.length())
    {
        int count = 0;
        if (s.at(i) == '(')
        {
            count++;
        }
        else
        {
            // Not starts with "(", skip.
            i++;
            continue;
        }

        int j = i + 1;
        while (j < s.length())
        {
            if (s.at(j) == '(')
            {
                count++;
            }
            else
            {
                count--;
            }

            // Check only if having enqual number of "(" and ")".
            // This can skip a bunch of extra "(" at the left.
            if (0 == count)
            {
                if (longest_number < j - i + 1)
                {
                    longest_number = j - i + 1;
                }
            }
            else if (0 > count)
            {
                break;
            }

            j++;
        }

        if (j < s.length())
        {
            // ')' are more than '(', can skip elements between i and j.
            i = j + 1;
        }
        else
        {
            i++;
        }
    }

    return longest_number;
}

