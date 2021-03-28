#include "header.h"

// Kind of brute forcr: get each of the digit in an array, 
// then two pointer to compare the digits from both front and 
// back towards the middle.
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    else if (x < 10)
    {
        return true;
    }

    bool result = true;

    vector<int> nums;

    while (x)
    {
        nums.push_back(x % 10);
        x /= 10;
    }

    for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
    {
        if (nums[i] != nums[j])
        {
            result = false;
            break;
        }
    }

    return result;
}