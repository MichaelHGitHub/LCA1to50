#include "header.h"

int removeElement(vector<int>& nums, int val)
{
    if (0 == nums.size())
    {
        return 0;
    }

    int end = nums.size() - 1;
    for (int i = 0; i <= end; i++)
    {
        while(end > i && nums[end] == val)
        {
            end--;
        }

        if (nums[i] == val)
        {
            nums[i] = nums[end];
            end--;
        }

        if (i >= end)
        {
            break;
        }
    }

    return end + 1;
}