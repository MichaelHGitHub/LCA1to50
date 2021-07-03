#include "header.h"

int searchInsert_r(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int last_larger = -1;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            last_larger = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return last_larger != -1 ? last_larger : nums.size();
}