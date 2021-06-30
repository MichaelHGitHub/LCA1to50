#include <algorithm>
#include "header.h"

// Two steps:
// 1. Find a pivot point where all digits after it need to be rearranged.
//    Search the pivot point this way:
// --- Start from pivot = nums.size() - 2(because we want to keep as many 
//     digits at the front untouched as possible), if any element after 
//     this point is larget than nums[pivot], this point is pivot.
// --- Swap the nums[pivot] with the lest value after pivot that is larger than
// ... nums[pivot].
// 2. Rearrange(sort) all the elements after pivot.

void nextPermutation_r(vector<int>& nums)
{
    int pivot_pos = nums.size() - 2;

    while (pivot_pos >= 0)
    {
        int next_dig_pos = -1;

        for (int i = pivot_pos + 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[pivot_pos])
            {
                if (next_dig_pos == -1 || nums[next_dig_pos] > nums[i])
                {
                    next_dig_pos = i;
                }
            }
        }

        if (next_dig_pos != -1)
        {
            int temp = nums[pivot_pos];
            nums[pivot_pos] = nums[next_dig_pos];
            nums[next_dig_pos] = temp;
            break;
        }
        --pivot_pos;
    }
    std::sort(nums.begin() + 1 + pivot_pos, nums.end());
}