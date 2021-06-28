#include "header.h"

int removeElement_r(vector<int>& nums, int val)
{
    int left = 0, right = 0;

    while (right < nums.size())
    {
        if (nums[right] != val)
        {
            nums[left++] = nums[right];
        }
        ++right;
    }

    return left;
}