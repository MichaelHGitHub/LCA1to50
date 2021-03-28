#include "header.h"


vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> result;

    if (nums.size() < 2)
    {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }

    // A map to save each element and its index
    map<int, int> numsMap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (numsMap.find(target - nums[i]) != numsMap.end())
        {
            result.push_back(numsMap[target - nums[i]]);
            result.push_back(i);
            break;
        }

        numsMap[nums[i]] = i;

    }

    return result;
}