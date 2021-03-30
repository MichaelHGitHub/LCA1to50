#include "header.h"


void PrepareTestData(vector<TD_VI_VI_D>& testData)
{
    TD_VI_VI_D data;

    data.input = { 1,3 };
    data.input2 = { 2 };
    data.output = 2.00000;

    testData.push_back(data);

    data.input = { 1,2 };
    data.input2 = { 3, 4 };
    data.output = 2.50000;

    testData.push_back(data);

    data.input = { 0,0 };
    data.input2 = { 0,0 };
    data.output = 0.00000;

    testData.push_back(data);

    data.input = { };
    data.input2 = { 1 };
    data.output = 1.00000;

    testData.push_back(data);

    data.input = { 2 };
    data.input2 = { };
    data.output = 2.00000;

    testData.push_back(data);

}