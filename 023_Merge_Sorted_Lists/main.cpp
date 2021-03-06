#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VL_L> testData;
    PrepareTestData(testData);

    for (int i = 0; i < testData.size(); i++)
    {
        PrintInput(testData[i]);

        ListNode* result = mergeKLists_r(testData[i].input);

        CheckResults(testData[i], result);
    }

    return 0;
}