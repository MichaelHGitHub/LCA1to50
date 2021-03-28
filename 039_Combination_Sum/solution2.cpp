#include "header.h"

// Start from the given offset, get all the combinations of elements whose sum is a given target
static void getCom(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int offset, int target);

// Recursive plus backtrack
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    vector<int> combination;

    getCom(result, combination, candidates, 0, target);

    return result;
}

// Start from the given offset, get all the combinations of elements whose sum is target
void getCom(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int offset, int target)
{
    if (offset == candidates.size() || target < 0)
    {
        return;
    }

    if (0 == target)
    {
        result.push_back(combination);
        return;
    }

    // Collect the combination starting from EACH of the election after offset,
    // element will be skipped one by one to cover all posibility.
    for (int i = offset; i < candidates.size(); i++)
    {
        combination.push_back(candidates[i]);
        getCom(result, combination, candidates, i, target - candidates[i]);
        combination.pop_back();
    }
}

