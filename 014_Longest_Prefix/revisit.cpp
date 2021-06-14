#include "header.h"

// 1. Find out the smallest length.
// 2. Check if half of the shortest length is common prefix
// ----2.1: if yes, check half of the second half next time.
// ----2.2: if not, check half of the first half next time.

string longestCommonPrefix_r(vector<string>& strs)
{
    string result;

    size_t shorest_length = INT32_MAX;

    for (int i = 0; i < strs.size(); i++)
    {
        shorest_length = min(shorest_length, strs[i].length());
    }

    int pre = -1;
    int cur = shorest_length - 1;

    while (pre < cur)
    {
        // Do binary search, begin = pre + 1, end = cur;
        int mid = (cur + pre + 1) / 2;
        char c = strs[0][mid];
        string prefix = strs[0].substr(pre + 1, mid - pre);
        for (int i = 1; i < strs.size(); i++)
        {
            if (c != strs[i][mid] || prefix != strs[i].substr(pre + 1, mid - pre))
            {
                cur = mid - 1;
                break;
            }
        }

        // if pre + 1 -> mid is common prefix. Move pre to the
        // last pos of the common prefix.
        if (cur > mid - 1)
        {
            pre = mid;
        }
    }

    if (pre > -1)
    {
        return strs[0].substr(0, pre + 1);
    }
    else
    {
        return "";
    }
}