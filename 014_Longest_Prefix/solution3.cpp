#include "header.h"

string longestCommonPrefix3(vector<string>& strs)
{
    if (strs.size() < 1)
    {
        return "";
    }
    else if (strs.size() == 1)
    {
        return strs[0];
    }

    for (int j = 0; j < strs[0].length(); j++)
    {
        for (int i = 1; i < strs.size(); i++)
        {
            if (j >= strs[i].length() ||
                strs[i].at(j) != strs[0].at(j))
            {
                return strs[0].substr(0, j);
            }
        }
        
 
    }

    return strs[0];
}