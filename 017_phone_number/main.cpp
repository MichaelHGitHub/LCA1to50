#include "header.h"

int main(char** args, int argc)
{
    vector<TD_S_VS> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);

        vector<string> result = letterCombinations_r(testData[i].input);

        CheckResults(testData[i], result);
    }


    return 0;
}
