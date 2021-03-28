#include "header.h"


// For a given element, we can find its best move, which is not necessarily the
// currently farthest, instead, it is the move that can jump farthest in the 
// next move. Repeat the seaching until reach the desination, then all the 
// best moves make up the best path to the destination.
// Special case:
// Only 1 element in the given array.

int jump2(vector<int>& nums)
{
    // Handle special case.
    if (nums.size() < 2)
    {
        return 0;
    }

    int count = 0;
    int current_index = 0;
    int current_fartherest = 0;
    int next_best_index = 0;
    int next_fartherest = 0;

    while (current_index < nums.size())
    {
        current_fartherest = current_index + nums[current_index];

        // Next jump will reach the destination, stop searching.
        if (current_fartherest >= nums.size() - 1)
        {
            ++count;
            break;
        }

        next_best_index = current_fartherest;
        next_fartherest = next_best_index + nums[next_best_index];

        // Check each option of the steps of that the current element can take,
        // find its best move, which is between [1, current_fartherest].
        for (int i = 1; i <= current_fartherest; i++)
        {
            if (i + nums[i] > next_fartherest)
            {
                next_best_index = i;
                next_fartherest = i + nums[i];
            }
        }

        ++count;

        // move to the index of the current's best move, and keep searching.
        current_index = next_best_index;
    }


    return count;
}

