#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VI_VI> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        nextPermutation(testData[i].input);
        CheckResults(testData[i], testData[i].input);
    }

    return 0;
}