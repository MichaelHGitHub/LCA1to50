#include "header.h"

int main(char** args, int argc)
{
    vector<TD_S_I> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);

        int result = longestValidParentheses_r2(testData[i].input);

        CheckResults(testData[i], result);
    }

    return 0;
}