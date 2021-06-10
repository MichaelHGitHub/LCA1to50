#include <unordered_map>
#include "header.h"

int lengthOfLongestSubstring_r2(string s)
{
    int result = 0;

    // pair: (s[i], i + 1). this is to avoid handling 0, which will 
    // confuse with the first indext in the string.
    unordered_map<char, int> visited;

    int left = 0, right = 0;

    while (left < s.length() && right < s.length())
    {
        // if s[right] appeared before, its flag in map is at least
        // left + 1.
        if (visited[s[right]] > left)
        {
            // Since the flag in map is index + 1, left has no need 
            // to plus 1.
            left = visited[s[right]];
        }

        result = max(result, right - left + 1);
        // Add index + 1 to map
        visited[s[right]] = right + 1;
        ++right;
    }

    return result;
}