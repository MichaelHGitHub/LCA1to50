#include "../common/sort.h"
#include "header.h"

// Loop the array, for each element, try to find another pair in the rest of the array
// using two sums algorithm. 
// The tricky part of the algorith is avoiding duplicate results. 
// Key point, 
    // 1. Sort the array. 
    // 2. If there are same values in the array, the far left value must be processed
    //      and skip the rest of the same value.
    // 3. Same principle applies to twoSum
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> three_zero_sum;

    if (nums.size() < 3)
    {
        return three_zero_sum;
    }

    // Sort the array first to facilitate avoiding duplicate results.
    quickSort(nums);

    for (int i = 0; i < nums.size() - 2; i++)
    {
        // Have to process the far left element before skipping duplicate number
        // otherwise some legitimate results could also be skipped.
        // For example: [-3, -3, 6, 8]
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int two_sum = 0 - nums[i];
        int low = i + 1;
        int high = nums.size() - 1;

        // Since it is an sorted array, use two pointers to find the two-sum elements.
        while (low < high)
        {
            // Again, have to process the far left same values before skipping.
            if (nums[low] + nums[high] == two_sum)
            {

                three_zero_sum.push_back({ nums[i], nums[low], nums[high] });

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

    return three_zero_sum;
}