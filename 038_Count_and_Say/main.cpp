#include "header.h"

int main(char** args, int argc)
{
    vector<TD_I_S> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        string result = countAndSay2(testData[i].input);
        CheckResults(testData[i], result);
    }

    return 0;
}