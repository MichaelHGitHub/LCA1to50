#include <algorithm>
#include "header.h"

vector<vector<int>> fourSum_r(vector<int>& nums, int target)
{
    vector<vector<int>> result;

    // Sort the array to get rid of duplication
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i <= (int)nums.size() - 4; i++)
    {
        // Skip duplicate elements if already processed.
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j <= (int)nums.size() - 3; j++)
        {
            // Skip duplicate elements if already processed.
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int target_of_two = target - nums[i] - nums[j];

            int low = j + 1;
            int high = nums.size() - 1;

            while (low < high)
            {
                int two_sum = nums[low] + nums[high];
                if (target_of_two == two_sum)
                {
                    result.push_back({ nums[i], nums[j], nums[low], nums[high]});
                    ++low;
                    --high;
                }
                else if (target_of_two > two_sum)
                {
                    ++low;
                }
                else
                {
                    --high;
                }

                // Skip duplicate elements if already processed. 
                // note: j+ 1 is the low boundary instead of 0.
                while(high > j + 1 && high < (int)nums.size() - 1 && nums[high] == nums[high + 1])
                {
                    --high;
                }

                // Skip duplicate elements if already processed.
                // note: j+ 1 is the low boundary instead of 0.
                while (low > j + 1 && low < (int)nums.size() - 1 && nums[low] == nums[low - 1])
                {
                    ++low;
                }
            }
        }
    }

    return result;
}