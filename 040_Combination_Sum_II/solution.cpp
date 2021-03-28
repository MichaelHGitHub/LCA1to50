#include <algorithm>
#include "header.h"

void getCombinations(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int offset, int target);

// Based on problem 39, just two things need to be modified:
// 1. skip duplicate elements when it is used as the first element in the combinations
// 2. the recursive call doesn't include current element so that one element
//    appears in one combination only once. 
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    vector<int> combination;

    // Sort the array to facilitate removing duplication
    std::sort(candidates.begin(), candidates.end());

    getCombinations(result, combination, candidates, 0, target);

    return result;
}


void getCombinations(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int offset, int target)
{
    // Have to check target = 0 before offset validity so that we don't skip
    // the last element.
    if (0 == target)
    {
        result.push_back(combination);
        return;
    }

    if (offset >= candidates.size() || target < 0)
    {
        return;
    }

    for (int i = offset; i < candidates.size(); i++)
    {
        // Skip the current one if it is equal to the previous one, which is 
        // already handled.
        if ((i != offset) &&
            (candidates[i-1] == candidates[i]))
        {
            continue;
        }

        combination.push_back(candidates[i]);
        // Since one element can only appear in one combination once,
        // the next iteration of recursive call starts from next element.
        getCombinations(result, combination, candidates, i + 1, target - candidates[i]);
        combination.pop_back();
    }
}