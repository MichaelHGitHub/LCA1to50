#include "header.h"

// Do a regular binary search to get lower boundary, if found, keep
// going to search(in the left half) for an even lower one until no match.
// Do the same thing to upper boundary except keep searching in the right 
// right half. 

vector<int> searchRange_r(vector<int>& nums, int target)
{
    int lower =-1;
    int upper = -1;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == nums[mid])
        {
            lower = mid;
            // Keep searching in the left half to find an even lower one.
            right = mid - 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    left = 0;
    right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == nums[mid])
        {
            upper = mid;
            // Keep searching in the right half to find an even upper one.
            left = left + 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return { lower, upper };
}