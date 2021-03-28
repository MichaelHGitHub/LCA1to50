#include <map>
#include "header.h"

static bool twoSum(vector<int>& nums, int target, int start, int end);
static bool threeSum(vector<int>& nums, int target);

int threeSumClosest(vector<int>& nums, int target)
{
    int result = 0;

    if (threeSum(nums, target))
    {
        result = target;
    }
    else
    {
        int up_closest = target + 1;
        int down_closest = target - 1;

        while (true)
        {
            if (threeSum(nums, up_closest))
            {
                result = up_closest;
                break;
            }

            if (threeSum(nums, down_closest))
            {
                result = down_closest;
                break;
            }

            up_closest++;
            down_closest--;
        }
    }

    return result;
}

bool twoSum(vector<int>& nums, int target, int start, int end)
{
    bool result = false;
    map<int, int> diff;

    for (int i = start; i <= end; i++)
    {
        if (diff.find(nums[i]) == diff.end())
        {
            diff[target - nums[i]] = i;
        }
        else
        {
            result = true;
            break;
        }
    }

    return result;
}

bool threeSum(vector<int>& nums, int target)
{
    bool result = false;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int two_sum = target - nums[i];
        if (twoSum(nums, two_sum, i + 1, nums.size() - 1))
        {
            result = true;
            break;
        }
    }

    return result;
}

