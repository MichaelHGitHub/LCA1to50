#include <unordered_map>
#include "header.h"

int lengthOfLongestSubstring_r(string s)
{

    int result = 0;
    unordered_map<char, int> visited;

    int left = 0, right = 0;

    while (left < s.length() && right < s.length())
    {
        if (visited.find(s[right]) != visited.end())
        {
            left = visited[s[right]] + 1;
            visited.clear();

            for (int i = left; i < right; i++)
            {
                visited[s[i]] = i;
            }
        }
        else
        {
            result = max(result, right - left + 1);
            visited[s[right]] = right;
            ++right;
        }
    }

    return result;
}