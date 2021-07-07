#include "header.h"

static void helper(vector<vector<int>>& results, vector<int> one_permutation, int pos, vector<int>& nums, vector<bool>& marks);

vector<vector<int>> permute_r(vector<int>& nums)
{
    vector<vector<int>> results;
    vector<int> one_permutation(nums.size(), 0);
    vector<bool> marks(nums.size(), false);

    helper(results, one_permutation, 0, nums, marks);

    return results;
}

static void helper(vector<vector<int>>& results, vector<int> one_permutation, int pos, vector<int>& nums, vector<bool>& marks)
{
    if (pos == one_permutation.size())
    {
        results.push_back(one_permutation);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!marks[i])
        {
            marks[i] = true;
            one_permutation[pos] = nums[i];
            helper(results, one_permutation, pos + 1, nums, marks);
            marks[i] = false;
            one_permutation[pos] = 0;
        }
    }
}