#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VVI_VVI> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        rotate(testData[i].input);
        CheckResults(testData[i], testData[i].input);
    }

    return 0;
}