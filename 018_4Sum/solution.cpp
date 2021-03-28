#include "../common/sort.h"
#include "header.h"

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;

    if (nums.size() < 4)
    {
        return result;
    }

    quickSort(nums);


    for (int i = 0; i < nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1 ; j < nums.size() - 2; j++)
        {
            // Have to process the far left element before skipping duplicate number
            // otherwise some legitimate results could also be skipped.
            // For example: [-3, -3, 6, 8]
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int two_sum = target - nums[i] - nums[j];
            int low = j + 1;
            int high = nums.size() - 1;

            // Since it is an sorted array, use two pointers to find the two-sum elements.
            while (low < high)
            {
                // Again, have to process the far left same values before skipping.
                if (nums[low] + nums[high] == two_sum)
                {

                    result.push_back({ nums[i], nums[j], nums[low], nums[high] });

                    // Only do skipping when find the right values, in other cases, they 
                    // will be skipped.
                    while (low < high && nums[low] == nums[low + 1])
                    {
                        low++;
                    }

                    while (low < high && nums[high] == nums[high - 1])
                    {
                        high--;
                    }

                    // the value of last nums[low] and nums[high] are processed, increase
                    // indexes.
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < two_sum)
                {
                    // this will skip the same values too.
                    low++;
                }
                else
                {
                    // this will skip the same values too.
                    high--;
                }
            }
        }
    }

    return result;
}