#include <algorithm>
#include "header.h"

void nextPermutation2(vector<int>& nums)
{
    if (nums.size() < 2)
    {
        return;
    }

    int lest_index = -1;
    int pos = nums.size() - 1;

    while (pos > 0)
    {
        if (nums[pos] > nums[pos - 1])
        {
            break;
        }

        pos--;
    }

    if (pos > 0)
    {
        for (int i = pos; i < nums.size(); i++)
        {
            if (-1 == lest_index || (nums[i] < nums[lest_index] && nums[pos - 1] < nums[i]))
            {
                lest_index = i;
            }
        }

        int temp = nums[pos - 1];
        nums[pos - 1] = nums[lest_index];
        nums[lest_index] = temp;
    }

    std::qsort(&nums[pos], nums.size() - pos, sizeof(int), [](const void* a, const void* b)
        {
            if (*(int*)a < *(int*)b)
            {
                return -1;
            }
            else if (*(int*)a > *(int*)b)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    );
}
