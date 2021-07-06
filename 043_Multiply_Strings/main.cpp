#include "header.h"

int main(char** args, int argc)
{
    vector<TD_S_S_S> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        string result = multiply_r(testData[i].input, testData[i].input2);
        CheckResults(testData[i], result);
    }

    return 0;
}