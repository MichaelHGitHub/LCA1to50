#include "header.h"

int removeDuplicates(vector<int>& nums)
{
    if (0 == nums.size())
    {
        return 0;
    }

    // position before which all elements are not replicate
    int p = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[p] != nums[i])
        {
            if ((i - 1 > p) && (nums[p] == nums[i - 1]))
            {
                // No need to swap, because the content after p doesn't matter.
                nums[p + 1] = nums[i];
            }
            p++;
        }
    }
    return (p + 1);
}
