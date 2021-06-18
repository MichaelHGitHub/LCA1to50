#include "header.h"

int main(char** args, int argc)
{
    vector<TD_L_L_L> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);
        ListNode* result = mergeTwoLists_r(testData[i].input, testData[i].input2);

        CheckResults(testData[i], result);
    }

    return 0;
}