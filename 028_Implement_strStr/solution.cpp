#include "header.h"


int strStr(string haystack, string needle)
{

    if (0 == needle.length())
    {
        return 0;
    }

    if (0 == haystack.length() || haystack.length() < needle.length())
    {
        return -1;
    }

    int first_occ = -1;

    int n_len = needle.length();
    int h_len = haystack.length();
    for (int i = 0; i < haystack.length(); i++)
    {
        int n_pos1 = 0;
        int n_pos2 = n_len - 1;
        int h_pos1 = i;
        int h_pos2 = i + n_len - 1;

        while (h_pos2 < h_len &&
            n_pos1<= n_pos2 &&
            haystack[h_pos1] == needle[n_pos1] && 
            haystack[h_pos2] == needle[n_pos2])
        {
            n_pos1++;
            n_pos2--;
            h_pos1++;
            h_pos2--;
        }

        if (n_pos1 > n_pos2)
        {
            first_occ = i;
            break;
        }
    }

    return first_occ;
}