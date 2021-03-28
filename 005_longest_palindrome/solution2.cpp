#include "header.h"

bool IsPalindrome2(string s)
{
    if (0 == s.length())
    {
        return false;
    }

    bool is_palindrome = true;

    // if s is palindrome, the left half must be the same as the right half.
    size_t mid = s.length() / 2;
    for (int i = 0; i < mid; i++)
    {
        if (s.at(i) != s.at(s.length() - i - 1))
        {
            is_palindrome = false;
            break;
        }
    }


    return is_palindrome;
}

string longestPalindrome2(string s)
{
    string lp;

    // i represent the number of the charecters in the sub string
    for (int i = 1; i <= s.length(); i++)
    {
        // j represent the starting pos of sub string
        for (int j = 0; j < s.length() - i + 1; j++)
        {
            string sub = s.substr(j, i);
            if (IsPalindrome2(sub))
            {
                if (lp.length() < sub.length())
                {
                    lp = sub;
                }
            }
        }
    }

    return lp;

}

