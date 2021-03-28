#include "header.h"

void PrepareTestData(vector<TD_I_B>& testData)
{
    TD_I_B data;

    data.input = 1234567899;
    data.output = false;
    testData.push_back(data);

    data.input = 121;
    data.output = true;
    testData.push_back(data);

    data.input = -121;
    data.output = false;
    testData.push_back(data);

    data.input = 10;
    data.output = false;
    testData.push_back(data);

    data.input = -101;
    data.output = false;
    testData.push_back(data);


}