#include "header.h"

// Start from the given offset, get all the combinations of elements whose sum is a given target
vector<vector<int>> getCom(vector<int>& candidates, int offset, int target);

// Recursive solution:
// For each of the element C[i], target/C[i] = times, remain r;
//  For each multiplier from 1 to times:
//      Start from C[i+1], try to find all the combination for target - C[i]*i,
//      Start from C[i+2](skipping C[i+1]), try to find all the combination for target - C[i]*i,
//      moving on until all the elements after i is covered. 
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;

    // Get the combinations for each elements in the array
    for (int i = 0; i < candidates.size(); i++)
    {
        vector<vector<int>> one_list = getCom(candidates, i, target);

        // Add each combination to the result array
        for (int j = 0; j < one_list.size(); j++)
        {
            result.push_back(one_list[j]);
        }
    }

    return result;
}

// Start from the given offset, get all the combinations of elements whose sum is target
vector<vector<int>> getCom(vector<int>& candidates, int offset, int target)
{
    vector<vector<int>> result;

    if (offset == candidates.size() || target <= 0)
    {
        return result;
    }

    int times = target / candidates[offset];
    int remain = target % candidates[offset];
    vector<int> s;

    // If target can be divided by candidate[offset], add it.
    if (0 == remain)
    {
        for (int t = 1; t <= times; t++)
        {
            s.push_back(candidates[offset]);
        }

        if (s.size() > 0)
        {
            result.push_back(s);
        }
    }

    // for each multiplier, try to find combination for (target - t * candidates[offset]),
    // in the rest of the array
    for (int t = 1; t <= times; t++)
    {
        // Starting from each element after offset, try to find all combinations
        // for (target - t * candidates[offset]), this covers cases where elements 
        // need to be skipped.
        for (int i = offset + 1; i < candidates.size(); i++)
        {
            // Start from the given pos, try to find all combination for (target - t * candidates[offset]).
            vector<vector<int>> pre_com = getCom(candidates, i, target - t * candidates[offset]);
            
            // If find combination, append t number of candiates[offset]
            for (int j = 0; j < pre_com.size(); j++)
            {
                for (int k = 1; k <= t; k++)
                {
                    pre_com[j].push_back(candidates[offset]);
                }

                result.push_back(pre_com[j]);
            }

        }

    }
    return result;
}

