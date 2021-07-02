#include "header.h"

// A variant of binary search

int search_r(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        // Before we do binary search, check left and right to get rid of
        // the affect of the edge values.
        // We could handle the edge values in other ways, but this is the
        // simplest way.
        if (nums[left] == target)
        {
            return left;
        }
        if (nums[right] == target)
        {
            return right;
        }

        // The following is just a variant of binary search.
        int mid = (right + left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            if (nums[mid] > nums[0])
            {
                if (nums[0] > target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            if (nums[mid] > nums[0])
            {
                left = mid + 1;
            }
            else
            {
                if (nums[nums.size() - 1] > target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
    }
    return -1;
}