
#include <unordered_set>
#include "header.h"

/// <summary>
/// Check if a string is a palindrome
/// </summary>
/// <param name="s">the s to check</param>
/// <param name="ps">a set that contains all the palindrome that have appeared so far</param>
/// <returns></returns>
bool IsPalindrome1(string s, unordered_set<string>& ps)
{
    if (s.length() == 0)
    {
        return false;
    }
    else if (s.length() == 1)
    {
        ps.insert(s);
        return true;
    }
    else if (s.length() == 2)
    {
        if (s.at(0) == s.at(1))
        {
            ps.insert(s);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // if s is palindrome, then the sub string left+1 to (right -1) must also
        // a palindrome and appear in the set since we check sub string from shorter
        // longer
        string sub = s.substr(1, s.length() - 2);
        if (ps.find(sub) != ps.end() && s.at(0) == s.at(s.length() - 1))
        {
            ps.insert(s);
            return true;
        }
        else
        {
            return false;
        }
    }
}

string longestPalindrome1(string s) {

    string lp;
    unordered_set<string> ps;

    // i represent the number of the charecters in the sub string
    for (int i = 1; i <= s.length(); i++)
    {
        // j represent the starting pos of sub string
        for (int j = 0; j < s.length() - i + 1; j++)
        {
            string sub = s.substr(j, i);
            if (IsPalindrome1(sub, ps))
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

