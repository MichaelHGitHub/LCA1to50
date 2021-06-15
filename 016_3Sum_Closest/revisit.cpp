#include <algorithm>
#include "header.h"

int threeSumClosest_r(vector<int>& nums, int target)
{
    int result = INT32_MAX;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int low = i + 1;
        int high = nums.size() - 1;

        while (low < high)
        {
            int sum = nums[i] + nums[low] + nums[high];

            if (target == sum)
            {
                return sum;
            }
            else if (target > sum)
            {

                ++low;
            }
            else
            {
                --high;
            }

            if (result == INT32_MAX || 
                abs(target - result) > abs(target - sum))
            {
                result = sum;
            }
        }
    }

    return result;
}