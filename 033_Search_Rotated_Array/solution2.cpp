#include "header.h"

int search2(vector<int>& nums, int target)
{
    if (0 == nums.size())
    {
        return -1;
    }

    int result = -1;
    int left = 0;
    int right = nums.size() - 1;

    while (right >= left)
    {
        if (nums[left] == target)
        {
            result = left;
            break;
        }

        if (nums[right] == target)
        {
            result = right;
            break;
        }

        int mid = (right + left) / 2;

        if (nums[mid] == target)
        {
            result = mid;
            break;
        }

        if (nums[mid] > nums[left])
        {
            if (nums[left] < target && nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = left + 1;
            }
        }
        else
        {
            if (nums[right] > target && nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return result;
}