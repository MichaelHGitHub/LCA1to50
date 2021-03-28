#include "../common/search.h"
#include "header.h"

// If target exists, find the first occurrence in the left rang of the array,
// and find the last occurrence in the right rang of the array.
// The way to find first/last occurrence is: keep looking for target in the
// left/right rang of the previous rang, until can't find one. This is also 
// binary search.
// Another idea: implement private version of find_first_of() 
// and find_last_of(), which starts searching from back towards front.
vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> result;

    // Empty array
    if (nums.size() < 1)
    {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }

    // Find an occurence of target using binary search
    int pos = binarySearch(nums, target, 0, nums.size() - 1);

    // target doesn't exist
    if (-1 == pos)
    {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }

    // Find the first occurrence in the left rang of the array
    int left = pos;
    if (0 != left)
    {
        int last_occur = -1;
        int begin = 0;
        int end = pos - 1;
        while (true)
        {
            last_occur = binarySearch(nums, target, begin, end);
            if (-1 != last_occur)
            {
                left = last_occur;
                end = last_occur - 1;
            }
            else
            {
                break;
            }
        }
    }
    
    // Find the last occurrence in the right rang of the array
    int right = pos;
    if (right != nums.size() - 1)
    {
        int last_occur = -1;
        int begin = pos + 1;
        int end = nums.size() - 1;
        while (true)
        {
            last_occur = binarySearch(nums, target, begin, end);

            if (-1 != last_occur)
            {
                right = last_occur;
                begin = last_occur + 1;
            }
            else
            {
                break;
            }
        }
    }

    result.push_back(left);
    result.push_back(right);
    return result;
}
