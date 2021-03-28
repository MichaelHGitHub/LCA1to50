#include "header.h"

static void permuteHelper(vector<vector<int>>& permutes, vector<int>& nums, int offset);

// We can build permutes by swaping elements.
// For each of the elements, it need to be swapped with every 
// element after. then recurrsively call the same function to get 
// the elements for the rest of the permute.

vector<vector<int>> permute3(vector<int>& nums)
{
    vector<vector<int>> result;

    permuteHelper(result, nums, 0);

    return result;
}

void permuteHelper(vector<vector<int>>& permutes, vector<int>& nums, int offset)
{
    // the index reaches last element, it is complete, add it.
    if (offset == nums.size() - 1)
    {
        permutes.push_back(nums);
        return;
    }

    // Build the current permute by swapping the current element with
    // each of the element after.
    for (int i = offset; i < nums.size(); i++)
    {
        swap(nums[i], nums[offset]);
        permuteHelper(permutes, nums, offset + 1);
        swap(nums[offset], nums[i]);
    }
}