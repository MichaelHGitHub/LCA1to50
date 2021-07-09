#include <map>
#include "header.h"

vector<vector<string>> groupAnagrams_r(vector<string>& strs)
{
    vector<vector<string>> result;
    map<vector<int>, int> anagram_patterns;

    for (int i = 0; i < strs.size(); i++)
    {
        vector<int> pattern(26, 0);

        for (int j = 0; j < strs[i].length(); j++)
        {
            pattern[strs[i][j] - 'a'] += 1;
        }

        if (anagram_patterns.find(pattern) == anagram_patterns.end())
        {
            result.push_back(vector<string>(1, strs[i]));
            anagram_patterns[pattern] = result.size() -1;
        }
        else
        {
            result[anagram_patterns[pattern]].push_back(strs[i]);
        }
    }
    return result;
}
