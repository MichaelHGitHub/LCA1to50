#include "header.h"

// Find the long string with unique charecters
int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
    {
        return s.length();
    }

    int sub_length = 0;
    size_t sub_begin = 0;

    for (int i = 0; i < s.length(); i++)
    {
        string sub = s.substr(sub_begin, i - sub_begin);

        if (sub.find_first_of(s.at(i)) != string::npos)
        {
            // find the char in the sub string means sub string stopps here.
            sub_begin = s.find_first_of(s.at(i), sub_begin) + 1;

            if (sub_length < sub.length())
            {
                sub_length = sub.length();
            }
        }
        else
        {
            // Doesn't find the char in the sub string, the search for the 
            // current sub string will go on.
            // Since the current char doesn't appear in the sub string. 
            // It will definitely become part of the sub string in next round.
            // Add it to the length. 
            // This covers the case that the longest one is at the end.
            sub_length = sub_length < (sub.length() + 1) ? static_cast<int>(sub.length() + 1) : sub_length;
        }
    }

    return sub_length;
}
