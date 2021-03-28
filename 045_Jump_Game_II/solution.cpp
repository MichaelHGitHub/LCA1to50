#include "header.h"

void jumpHelper(vector<int>& nums, int offset, int actual_step, int& min_step);

int jump(vector<int>& nums)
{
    int min_step = INT32_MAX;
    jumpHelper(nums, 0, 0, min_step);

    return min_step;
}

// Brute force
// For each element, enumerate its all possible steps and eventually get the steps
// of each path, return the smallest steps of all the path.
// Performance is not good, not accepted.
void jumpHelper(vector<int>& nums, int offset, int actual_step, int& min_step)
{
    if (offset == nums.size() - 1)
    {
        min_step = (min_step < actual_step) ? min_step : actual_step;
        return;
    }

    if (offset >= nums.size())
    {
        return;
    }

    if (offset == nums.size() - 2)
    {
        actual_step++;
        min_step = (min_step < actual_step) ? min_step : actual_step;
        return;
    }

    // Try each possible step number
    for (int j = nums[offset]; j > 0; j--)
    {
        // Process next element
        jumpHelper(nums, offset + j, actual_step + 1, min_step);
    }
}