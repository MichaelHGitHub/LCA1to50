#include "header.h"

static void helper(vector<vector<int>>& results, vector<int>& one_result, vector<int>& candidates, int start, int target);

vector<vector<int>> combinationSum_r(vector<int>& candidates, int target)
{
    vector<vector<int>> results;
    vector<int> one_result;
    helper(results, one_result, candidates, 0, target);

    return results;
}

void helper(vector<vector<int>>& results, vector<int>& one_result, vector<int>& candidates, int start, int target)
{
    if (target == 0)
    {
        results.push_back(one_result);
    }

    if (target < 0)
    {
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        one_result.push_back(candidates[i]);
        helper(results, one_result, candidates, i, target - candidates[i]);
        one_result.pop_back();
    }
}