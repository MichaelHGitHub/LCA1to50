#include "header.h"

int main(char** args, int argc)
{
    vector<TD_VI_VI_D> test_data = {};

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        double result = findMedianSortedArrays2(test_data[i].input, test_data[i].input2);

        CheckResults(test_data[i], result);
    }

    return 0;
}

