#include "header.h"


void PrepareTestData(vector<TD_VI_I_VI>& testData)
{
    TD_VI_I_VI data;

    data.input = { 2, 2 };
    data.input2 = 2;
    data.output = { 0, 1 };
    testData.push_back(data);

    data.input = { 5,7,7,8,8,10 };
    data.input2 = 8;
    data.output = { 3,4 };
    testData.push_back(data);

    data.input = { 5,7,7,8,8,10 };
    data.input2 = 6;
    data.output = { -1,-1 };
    testData.push_back(data);

    data.input = {};
    data.input2 = 0;
    data.output = { -1,-1 };
    testData.push_back(data);
}