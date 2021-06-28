#include "header.h"

int main(char** args, int argc)
{
    vector<TD_S_S_I> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);

        int result = strStr_r(testData[i].input, testData[i].input2);

        CheckResults(testData[i], result);
    }

    return 0;
}