#include "header.h"

int strStr_r(string haystack, string needle)
{
    if (needle.size() == 0)
    {
        return 0;
    }

    for (int i = 0; i < haystack.size(); i++)
    {
        int j = 0;
        for (;j < needle.size(); j++)
        {
            if (i+ j >= haystack.size() || haystack[i + j] != needle[j])
            {
                break;
            }
        }

        if (j == needle.size())
        {
            return i;
        }

        if (i + j >= haystack.size())
        {
            return -1;
        }
    }

    return -1;
}