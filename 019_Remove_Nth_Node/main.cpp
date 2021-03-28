#include "header.h"

int main(char** args, int argc)
{
    vector<TD_L_I_L> testData;
    PrepareTestData(testData);

    

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        ListNode* result = removeNthFromEnd2(testData[i].input, testData[i].input2);

        CheckResults(testData[i], result);
    }

    return 0;
}