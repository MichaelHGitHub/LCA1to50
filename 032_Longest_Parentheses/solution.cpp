#include "header.h"

int isParentheses(string& s, int start, int count);

// This solution is not efficient enough to pass test case 5
int longestValidParentheses(string s)
{
    int longest_number = 0;

    int i = 0;
    while (i < s.length())
    {
        int j = i + 1;
        while(j < s.length())
        {
            if (s.at(i) == '(' && s.at(j) == ')')
            {
                int balance = isParentheses(s, i, j - i + 1);
                if (0 == balance)
                {
                    if (longest_number < j - i + 1)
                    {
                        longest_number = j - i + 1;
                    }
                }
                else if (0 > balance)
                {
                    // ')' are more than '('
                    break;
                }
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

int isParentheses(string& s, int start, int count)
{
    int balance = 0;

    for (int i = start; i < start + count; i++)
    {
        if (s[i] == ')')
        {
            balance--;
            // This ensure no ')' being deplay calculated.
            // As long as no '(' to match ')', return false.
            if (balance < 0)
            {
                break;
            }
        }
        else
        {
            balance++;
        }
    }

    return balance;
}