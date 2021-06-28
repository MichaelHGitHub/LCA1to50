#include "header.h"

int removeDuplicates_r(vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    int left = 0, right = 0;

    while (right < nums.size())
    {
        if (nums[right] != nums[left])
        {
            nums[++left] = nums[right];
        }
        ++right;
    }
    return left + 1;
}