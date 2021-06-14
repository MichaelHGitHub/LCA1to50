#include <unordered_map>
#include <algorithm>
#include "header.h"

vector<vector<int>> threeSum_r(vector<int>& nums)
{
    vector<vector<int>> result;

    std:sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            break;
        }

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        unordered_map<int, int> visited;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int diff = -nums[i] - nums[j];
            if (visited.find(diff) != visited.end())
            {
                if (j > i + 1 && nums[j] == nums[j - 1] && visited[diff] != j - 1)
                {
                    continue;
                }

                vector<int> three_elements;
                three_elements.push_back(nums[i]);
                three_elements.push_back(nums[visited[diff]]);
                three_elements.push_back(nums[j]);
                result.push_back(three_elements);
            }
            else
            {
                visited[nums[j]] = j;
            }
        }
    }
    return result;
}