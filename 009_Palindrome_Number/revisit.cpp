#include "header.h"

bool isPalindrome_r(int x)
{
    if (x < 0)
    {
        return false;
    }

    vector<int> nums;
    while (x)
    {
        nums.push_back(x % 10);
        x /= 10;
    }

    int i = 0;
    int j = nums.size() - 1;
    while (i < j)
    {
        if (nums[i++] != nums[j--])
        {
            return false;
        }
    }

    return true;
}