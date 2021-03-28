#include "header.h"

bool isMatchHelper(string& s, int si, string& p, int pi);

bool isMatch(string s, string p)
{
    return isMatchHelper(s, 0, p, 0);
}

bool isMatchHelper(string& s, int si, string& p, int pi)
{
    // If string and p are all empty, then it matches. 
    // If string is empty and pattern not, need to proceed to try to remove valid (x*)
    // If string is not empty and patter is, it doesn't match. 
    if (pi == p.length())
    {
        return (si == s.length());
    }

    bool first_match = (si < s.length() && (s.at(si) == p.at(pi) || p.at(pi) == '.'));

    // Pattern begins with (x*), the following two branch(with x* and without x*) will cover
    // x* matches 0 or multiple chars.

    // Try to match the whole string without asterisk( in the case where x* matches 0 time)
    // First match doesn't make sense in this case because first 2 chars in patter will be 
    // removed.
    if (pi < p.length() - 1 && p.at(pi + 1) == '*')
    {
        if (isMatchHelper(s, si, p, pi + 2))
        {
            return true;
        }
        // First char matches with (x*), and try to match more chars using (x*) in the pattern.
        else if(first_match && isMatchHelper(s, si + 1, p, pi))
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
        if (first_match && isMatchHelper(s, si + 1, p, pi + 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}