#include "header.h"

// Basically, the solution will be a binary search, meanwhile
// save the postion of last element less than target amid the 
// searching.
// If target doesn't exit, the insert postion will be 
// the position of last less element plus one.
int searchInsert(vector<int>& nums, int target)
{
    if (nums.size() < 1)
    {
        return 0;
    }

    int result = -1;

    vector<int>::iterator it = nums.end();

    int left = 0;
    int right = nums.size() - 1;

    // Init the last_less to -1 so that we don't even need to 
    // check if last_less exits.
    int last_less = -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
        {
            result = mid;
            break;
        }
        else if (nums[mid] < target)
        {
            last_less = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (-1 == result)
    {
        result = last_less + 1;
    }

    return result;
}