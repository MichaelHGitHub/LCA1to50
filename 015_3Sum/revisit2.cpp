#include <algorithm>
#include "header.h"

vector<vector<int>> threeSum_r2(vector<int>& nums)
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

        int low = i + 1;
        int high = nums.size() - 1;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            if (sum == -nums[i])
            {
                vector<int> three_elements;
                three_elements.push_back(nums[i]);
                three_elements.push_back(nums[low]);
                three_elements.push_back(nums[high]);
                result.push_back(three_elements);

                while (low < nums.size() - 1 && nums[low] == nums[low + 1])
                {
                    ++low;
                }

                while (high > 0 && nums[high] == nums[high - 1])
                {
                    --high;
                }

                ++low;
                --high;
            }
            else if (sum > -nums[i])
            {
                --high;
            }
            else
            {
                ++low;
            }
        }
    }
    return result;
}