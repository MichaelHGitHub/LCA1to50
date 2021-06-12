#include "header.h"

static bool helper(string& s, int bs, string& p, int bp);

bool isMatch_r(string s, string p)
{
    return helper(s, 0, p, 0);
}

bool helper(string& s, int bs, string& p, int bp)
{
    int i = bs;
    int j = bp;

    while (j < p.length())
    {
        // If find (x*), handle it recursively.
        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            // Repeat (x*) 0 time
            if (helper(s, i, p, j + 2))
            {
                return true;
            }

            // Repeat (x*) 1-n times
            // Check s[i+count-1] == p[j], if pass, recursively call helper moving to next phase
            int count = 1;
            while (i + count - 1 < s.length() && (s[i + count - 1] == p[j] || p[j] == '.'))
            {
                if (helper(s, i + count, p, j + 2))
                {
                    return true;
                }
                ++count;
            }
            return false;
        }
        else if (i < s.length() && (p[j] == '.' || s[i] == p[j]))
        {
            // Normal matching
            ++i;
            ++j;
        }
        else
        {
            return false;
        }
    }

    // If both string reach end, true, otherwise false.
    return i == s.length() && j == p.length();
}