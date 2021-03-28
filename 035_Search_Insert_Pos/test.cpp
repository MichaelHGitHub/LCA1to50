#include "header.h"

void PrepareTestData(vector<TD_VI_I_I>& testData)
{
    TD_VI_I_I data;

    data.input = { 1,3,5,6 };
    data.input2 = 5;
    data.output = 2;
    testData.push_back(data);

    data.input = { 1,3,5,6 };
    data.input2 = 2;
    data.output = 1;
    testData.push_back(data);

    data.input = { 1,3,5,6 };
    data.input2 = 7;
    data.output = 4;
    testData.push_back(data);

    data.input = { 1,3,5,6 };
    data.input2 = 0;
    data.output = 0;
    testData.push_back(data);

    data.input = { 1 };
    data.input2 = 0;
    data.output = 0;
    testData.push_back(data);
}