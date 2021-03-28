#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VI_I_VVI> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        vector<vector<int>> result = combinationSum(testData[i].input, testData[i].input2);
        CheckResults_Unorder(testData[i], result);
    }

    return 0;
}