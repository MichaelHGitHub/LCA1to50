#include <algorithm>
#include "header.h"

static void helper(vector<vector<int>>& results, vector<int>& one_result, vector<int>& candidates, int start, int target);

vector<vector<int>> combinationSum2_r(vector<int>& candidates, int target)
{
    vector<vector<int>> results;
    vector<int> one_result;

    std::sort(candidates.begin(), candidates.end());
    helper(results, one_result, candidates, 0, target);

    return results;
}

void helper(vector<vector<int>>& results, vector<int>& one_result, vector<int>& candidates, int start, int target)
{
    if (target == 0)
    {
        results.push_back(one_result);
    }

    if (start >= candidates.size() || target < 0)
    {
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        if (i > start && candidates[i] == candidates[i - 1])
        {
            continue;
        }

        one_result.push_back(candidates[i]);
        helper(results, one_result, candidates, i + 1, target - candidates[i]);
        one_result.pop_back();
    }
}