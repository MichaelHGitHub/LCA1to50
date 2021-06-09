#include "header.h"

void PrepareTestData(vector<TD_VS_S>& test_data)
{
    TD_VS_S data;

    // This is the test that is missing from leetcode
    // Opened an issue for them:
    // #3170: https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/3170
    data.input = { "flower", "flawer", "flvwer", "flower" };
    data.output = "fl";
    test_data.push_back(data);

    data.input = { "flower", "flower", "flower", "flower" };
    data.output = "flower";
    test_data.push_back(data);

    data.input = { "flower","flow","flight" };
    data.output = "fl";
    test_data.push_back(data);

    data.input = { "dog","racecar","car" };
    data.output = "";
    test_data.push_back(data);

}