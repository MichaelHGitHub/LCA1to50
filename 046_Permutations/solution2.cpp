#include "header.h"

static void permuteHelper(vector<vector<int>>& permutes, vector<int>& nums, bool* selection, vector<int>& one_permute);

vector<vector<int>> permute2(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> one_permute;

    bool* selection = new bool[nums.size()];
    memset(selection, 0, sizeof(bool) * nums.size());

    permuteHelper(result, nums, selection, one_permute);

    delete[] selection;

    return result;
}

// For each of the element in the given array, build a permute starting with the 
// current element.
// When building one permute, choose one element from the given array at a time, and 
// mark the element as choosen. Recurrsively call this function to choose the next
// element. If the one element is already choosen at above level, it will be skipped.
// Once the length of one permute reaches its full size, add it to the results container.
// When the function return from one of the recurrsive call, remove the current element 
// from the current permute and erase the selection mark of the current element so that 
// the building of another permute is not affected.
// 
void permuteHelper(vector<vector<int>>& permutes, vector<int>& nums, bool* selection, vector<int>& one_permute)
{
    // the current permute reaches its full size, it is complete, add it.
    if (one_permute.size() == nums.size())
    {
        permutes.push_back(one_permute);
        return;
    }

    // In process of building the current permute
    for (int i = 0; i < nums.size(); i++)
    {
        // Skip the element that has been choosen in above level.
        if (selection[i])
        {
            continue;
        }

        // choosen nums[i] and mark it as choosen
        selection[i] = true;
        one_permute.push_back(nums[i]);
        // Recurrsively choose next element
        permuteHelper(permutes, nums, selection, one_permute);

        // clean up for the current element, and choose next element from the 
        // given array.
        one_permute.pop_back();
        selection[i] = false;
    }
}