#include "header.h"

int searchLastIndex(vector<int>& nums);
int binarySearch(vector<int>& nums, int target, int left, int right);

// Algorithm: if we can find the location of the original last element, we can 
// divide the array into 2 parts, both sub arrays are ascently sorted. then 
// we can do binary search in either first or second part to find target.
//  1. Do binary search to find the current index of the original last element, say i. 
//  2. If target > k(numa[0]), then binary search to find target in nums[0, i],
//     otherwise in nums[i+1, n]
//

int search(vector<int>& nums, int target)
{
    if (0 == nums.size())
    {
        return -1;
    }

    int result = -1;

    if (target == nums[0])
    {
        result = 0;
    }
    else
    {
        int last_index = searchLastIndex(nums);
        if (target < nums[0])
        {
            result = binarySearch(nums, target, last_index + 1, nums.size() - 1);
        }
        else
        {
            result = binarySearch(nums, target, 0, last_index);
        }
    }

    return result;
}

int searchLastIndex(vector<int>& nums)
{
    if (nums.size() < 2)
    {
        return 0;
    }

    int last_index = -1;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (right + left) / 2;

        // When mid reaches 0
        if (mid == 0 && nums[mid] > nums[mid + 1])
        {
            last_index = mid;
            break;
        }
        // When mid reaches last element
        else if(mid == nums.size() - 1 && nums[mid] > nums[mid - 1])
        {
            last_index = mid;
            break;
        }
        else
        {
            // mid is in between 0 and n-1
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
            {
                last_index = mid;
                break;
            }
            // if nums[mid] < k, the largest element must be in the left part
            else if (nums[mid] < nums[0])
            {
                right = mid - 1;
            }
            // if nums[mid] > k, the largest element must be in the right part
            else
            {
                left = mid + 1;
            }
        }
    }

    return last_index;
}

int binarySearch(vector<int>& nums, int target, int left, int right)
{
    if (0 == nums.size())
    {
        return -1;
    }

    int result = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (target == nums[mid])
        {
            result = mid;
            break;
        }
        else if(target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}