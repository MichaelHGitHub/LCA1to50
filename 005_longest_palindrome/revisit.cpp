#include <set>
#include "header.h"

// Check sub string length from 2 to n, if a substr is palindrome, save the pair(start, end)
// to a set.
// when check substr(start, end), if s[start] == s[end], and sub(start + 1, end -1) in the visited
// set, then sub(start, end) is a palindrome.

string longestPalindrome_r(string s)
{
    // First get rid of those really long and palindrome cases.
    if (s == string(s.rbegin(), s.rend()))
    {
        return s;
    }

    int start = 0, end = 0;
    set<pair<int, int>> pairs;

    // Start from length 2, because 1 char string is always palindrome
    for (int c = 2; c <= s.length(); c++)
    {
        int i = 0;
        int j = i + c - 1;
        while (j < s.length())
        {
            if (s[i] == s[j])
            {
                if (j - i < 3)
                {
                    pairs.insert(pair<int, int>(i, j));
                    if (j - i > end - start)
                    {
                        start = i;
                        end = j;
                    }
                }
                else if (pairs.find(pair<int, int>(i + 1, j - 1)) != pairs.end())
                {
                    pairs.insert(pair<int, int>(i, j));
                    if (j - i > end - start)
                    {
                        start = i;
                        end = j;
                    }
                }
            }
            ++i;
            j = i + c - 1;
        }
    }
    return s.substr(start, end - start + 1);
}