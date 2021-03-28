#include "header.h"

int main(char** args, int argc)
{
    vector<TD_I_I_I> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);

        int result = divide(testData[i].input, testData[i].input2);

        CheckResults(testData[i], result);
    }

    return 0;
}