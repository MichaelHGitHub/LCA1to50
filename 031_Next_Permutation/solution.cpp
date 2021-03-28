#include <algorithm>
#include "header.h"

//
// Giving an array {a[0], a[1]...a[n]}
// To make the next permutation, we need to:
//  1. find an index i where:
//      1.1. i is as close to the end as possible
// .....1.2  a[i] > a[i-1]
//  2. swap a[i-1] with the element a[j] that in the latter part of the array, where:
//      2.1 a[j] > a[i-1]
//      2.2 a[j] is as small as possible
//  3. sort elements between i and the end in ascent order
// 
void nextPermutation(vector<int>& nums)
{
    if (nums.size() < 2)
    {
        return;
    }

    // Find the postion where we need to swap
    vector<int>::iterator pos = nums.end() - 1;
    while (pos != nums.begin())
    {
        if (*pos > *(pos-1))
        {
            break;
        }

        pos--;
    }

    if (pos != nums.begin())
    {
        // Found the position(pos-1) where we need to swap elements. the next thing is
        // to find the smallest element in latter part of the array that is also larger
        // than the element at (pos-1), and swap the element with element at (pos-1)
        vector<int>::iterator less_pointer = nums.end();
        for (vector<int>::iterator i = pos; i != nums.end(); i++)
        {
            if (less_pointer == nums.end() || (*i < *less_pointer && *(pos-1) < *i))
            {
                less_pointer = i;
            }
        }

        int temp = *(pos - 1);
        *(pos - 1) = *less_pointer;
        *less_pointer = temp;
    }

    // Finally, sort the latter part of the array, if no swapping point is found,
    // sort the entire array
    std::sort(pos, nums.end());
}