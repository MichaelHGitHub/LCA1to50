#include <algorithm>
#include <unordered_map>
#include "header.h"

// We need to find a common representation for each group of strings
// such that we can easily check if the current string belongs to an 
// exist group or a new one. 
// We can use the sorted version of the current string as the group's
// representitive. Save it in a map<representive, group-index>. 
// As we loop through the strings, if the string's representitive exits
// in the map, retrieve its group index and add the string to that group, 
// otherwise, add it to a new group.
// 
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    unordered_map<string, int> records;

    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());

        unordered_map<string, int>::iterator it = records.find(s);
        if (it == records.end())
        {
            // Add a new group
            records[s] = result.size();
            vector<string> v;
            v.push_back(strs[i]);
            result.push_back(v);
        }
        else
        {
            // Add to an exit group
            result[it->second].push_back(strs[i]);
        }
    }

    return result;
}