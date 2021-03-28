#include "header.h"

static vector<vector<int>> permuteHelper(vector<int>& nums, int offset);

vector<vector<int>> permute(vector<int>& nums)
{
    return permuteHelper(nums, 0);
}

// build all the permutes of [nums[i], num[n]] as:
// 1. first get all the permute of [nums[i+1], num[n]].
// 2. For each of the permute(p) in above result, build (n + 1 -i) new permutes by
// placing nums[i] in each of the postion from 0 to end with rest of the 
// elements coming from the permute(p).
// 
vector<vector<int>> permuteHelper(vector<int>& nums, int offset)
{
    int level = nums.size() - offset;
    vector<vector<int>> permutes;

    if (1 == level)
    {
        permutes.push_back(vector<int>(1, nums[offset]));
        return permutes;
    }

    // Get permutes for offset + 1
    vector<vector<int>> pre_permutes = permuteHelper(nums, offset + 1);

    // for each of the permutes of (offset + 1), build (nums.size() - offset) new 
    // permutes.
    for (int i = 0; i < pre_permutes.size(); i++)
    {
        // Place nums[offset] in postion from 0 to end of above permute.
        for (int j = 0; j < level; j++)
        {
            vector<int> one_permute;

            if (0 != j)
            {
                one_permute.assign(pre_permutes[i].begin(), pre_permutes[i].begin() + j);
            }
            one_permute.push_back(nums[offset]);
            one_permute.insert(one_permute.end(), pre_permutes[i].begin() + j, pre_permutes[i].end());

            permutes.push_back(one_permute);
        }
    }

    return permutes;
}