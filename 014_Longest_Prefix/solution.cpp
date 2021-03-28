#include "header.h"

// Could use brute force to compare char by char in each of the strings,
// the time complexity would be O( m * n) while m = string0.lengther and 
// n = numbers of strings.
// In this solution, I do binary search in string0, the time complexity 
// therefore reduces to O(log(m) * n)
string longestCommonPrefix(vector<string>& strs)
{
    if (strs.size() < 1)
    {
        return "";
    }
    else if(strs.size() == 1)
    {
        return strs[0];
    }

    int sub_count = strs[0].length();
    int last_pass = 0;

    while (sub_count > last_pass && sub_count <= strs[0].length())
    {
        bool pass = true;
        string sub = strs[0].substr(0, sub_count);

        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i].substr(0, sub_count) != sub)
            {
                pass = false;
                break;
            }
        }

        if (pass)
        {
            last_pass = sub_count;
            sub_count = (strs[0].length() + sub_count) / 2;
        }
        else
        {
            sub_count = (sub_count + last_pass) / 2;
        }
    }

    return strs[0].substr(0, last_pass);
}