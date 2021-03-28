#include "header.h"

// Expand both wards, check if the corresponding 
// charecters are equal.
int expandCenter(string s, int left, int right)
{
    int l = left;
    int r = right;
    while ((l >= 0 && r < s.length()) && (s.at(l) == s.at(r)))
    {
        l--;
        r++;
    }

    return (r - l -1);
}

string longestPalindrome3(string s)
{
    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++)
    {
        // Check palindrome of oder number of charecters
        int len1 = expandCenter(s, i, i);
        // Check palindrome of even number of charecters 
        int len2 = expandCenter(s, i, i + 1);

        int len = len1 > len2 ? len1 : len2;

        // Remember the start and end pos of the larger palindrome. 
        if (len > end - start +1 )
        {
            start = i - len / 2 + (len + 1) % 2;
            end = i + (len / 2);
        }

    }

    return s.substr(start, end - start + 1);
}