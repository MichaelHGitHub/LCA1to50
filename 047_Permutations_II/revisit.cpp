#include <algorithm>
#include "header.h"

static void helper(vector<vector<int>>& results, vector<int>& one_permutation, vector<int>& nums, int pos, vector<bool> marks);

vector<vector<int>> permuteUnique_r(vector<int>& nums)
{
    vector<vector<int>> results;
    vector<int> one_permutation(nums.size(), 0);
    vector<bool> marks(nums.size(), false);
    std::sort(nums.begin(), nums.end());
    
    helper(results, one_permutation, nums, 0, marks);

    return results;
}

void helper(vector<vector<int>>& results, vector<int>& one_permutation, vector<int>& nums, int pos, vector<bool> marks)
{
    if (pos == one_permutation.size())
    {
        results.push_back(one_permutation);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1] && marks[i - 1])
        {
            continue;
        }

        if (!marks[i])
        {
            one_permutation[pos] = nums[i];
            marks[i] = true;
            helper(results, one_permutation, nums, pos + 1, marks);
            one_permutation[pos] = 0;
            marks[i] = false;
        }
    }
}