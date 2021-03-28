#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VI_I> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);

        int result = removeDuplicates(testData[i].input);

        CheckResults(testData[i], result);
    }

    return 0;
}