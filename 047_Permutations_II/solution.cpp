#include <unordered_set>
#include "header.h"

static void permuteHelper(vector<vector<int>>& permutes, vector<int>& nums, int offset);

vector<vector<int>> permuteUnique(vector<int>& nums)
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

    unordered_set<int> used;
    // In process of building the current permute
    for (int i = offset; i < nums.size(); i++)
    {
        if(used.find(nums[i]) == used.end())
        {
            used.insert(nums[i]);

            swap(nums[i], nums[offset]);
            permuteHelper(permutes, nums, offset + 1);
            swap(nums[offset], nums[i]);
        }
    }
}