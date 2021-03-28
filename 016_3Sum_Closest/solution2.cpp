#include <map>
#include <algorithm>
#include "header.h"

static int twoSumClosest(vector<int>& nums, int target, int start, int end);

//
// For each element nums[i](except last two elements), try to find a two_sum in the
// rest of the array, so that the two_sum is the closest number to (target - nums[i]),
// thus the three_sum(two_sum + nums[i]) the closest number to target.
//
int threeSumClosest2(vector<int>& nums, int target)
{
    // Sort the array so that we can use two pointer to calculate two sum later.
    sort(nums.begin(), nums.end());

    // Initialize the closest sum to its possible max
    int closest = 3000; // (max_a(10 ^ 3) + max_b(10 ^ 3) + max_b(10 ^ 3))

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int two_closest = twoSumClosest(nums, target - nums[i], i + 1, nums.size() - 1);
        if (two_closest + nums[i] == target)
        {
            closest = target;
            break;
        }
        else
        {
            // Check which is closer to the target
            if (abs(closest - target) > abs(two_closest + nums[i] - target))
            {
                closest = two_closest + nums[i];
            }
        }
    }

    return closest;
}

// Use two pointers to find the closest two sum to target
int twoSumClosest(vector<int>& nums, int target, int start, int end)
{
    // Initialize the closest sum to its possible max
    int closest = 2000; // (max_a(10^3) + max_b(10^3))
    int low = start;
    int high = end;

    while (low < high)
    {
        int two_sum = nums[low] + nums[high];
        if (two_sum == target)
        {
            closest = target;
            break;
        }
        else
        {
            // Check which is closer to the target
            if (abs(closest - target) > abs(two_sum - target))
            {
                closest = two_sum;
            }

            (two_sum > target) ? high-- : low++;
        }
    }
    return closest;
}
