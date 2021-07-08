#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VI_VVI> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        vector<vector<int>> result = permuteUnique_r(testData[i].input);
        CheckResults_Unorder(testData[i], result);
    }

    return 0;
}