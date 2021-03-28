#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VS_VVS> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        vector<vector<string>> result = groupAnagrams(testData[i].input);
        CheckResults_Unoder(testData[i], result);
    }

    return 0;
}