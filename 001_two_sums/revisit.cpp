#include <unordered_map>
#include "header.h"

// Revisit
vector<int> twoSum_r(vector<int>& nums, int target)
{
    vector<int> result;

    unordered_map<int, int> visited;

    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if (visited.find(diff) != visited.end())
        {
            result.push_back(i);
            result.push_back(visited[diff]);
            break;
        }
        else
        {
            visited[nums[i]] = i;
        }
    }

    return result;

}
