#include "header.h"

int jump_r(vector<int>& nums)
{
    vector<int> steps(nums.size(), INT32_MAX);
    steps[steps.size() - 1] = 0;

    for (int i = steps.size() - 2; i >= 0; i--)
    {
        int min_steps = INT32_MAX;

        for (int j = i + 1; j < steps.size() && j <= i + nums[i]; j++)
        {
            min_steps = min(min_steps, steps[j]);
        }

        steps[i] = (min_steps == INT32_MAX ? INT32_MAX: min_steps + 1);
    }

    return steps[0];
}