#include "header.h"

bool isMatch2(string s, string p)
{
    // If string and p are all empty, then it matches. 
    // If string is empty and pattern not, need to proceed to try to remove valid (x*)
    // If string is not empty and patter is, it doesn't match. 
    if (p.empty())
    {
        return s.empty();
    }

    bool first_match = false;

    if (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.'))
    {
        first_match = true;
    }

    if (p.length() > 1 && p.at(1) == '*')
    {
        // Pattern begins with (x*), the following two branch(with x* and without x*) will cover
        // x* matches 0 or multiple chars.

        // Try to match the whole string without asterisk( in the case where x* matches 0 time)
        // First match doesn't make sense in this case because first 2 chars in patter will be 
        // removed.
        if (isMatch(s, p.substr(2, p.length() - 2)))
        {
            return true;
        }
        // First char matches with (x*), and try to match more chars using (x*) in the pattern.
        else if (first_match && isMatch(s.substr(1, s.length() - 1), p))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // Pattern deosn't begin with(char*), has to match next char recursively.
        if (first_match && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}