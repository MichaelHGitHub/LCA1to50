#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VVC_B> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);

        bool result = isValidSudoku(testData[i].input);

        CheckResults(testData[i], result);
    }

    return 0;
}