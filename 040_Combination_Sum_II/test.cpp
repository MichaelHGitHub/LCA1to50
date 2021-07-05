#include "header.h"

void PrepareTestData(vector<TD_VI_I_VVI>& testData)
{
    TD_VI_I_VVI data;

    data.input = { 2,2,2,2 };
    data.input2 = 2;
    data.output = { {2} };
    testData.push_back(data);

    data.input = { 10,1,2,7,6,1,5 };
    data.input2 = 8;
    data.output = { {1,1,6}, {1,2,5}, {1,7}, {2,6} };
    testData.push_back(data);

    data.input = { 2,5,2,1,2 };
    data.input2 = 5;
    data.output = { {1,2,2} ,{5} };
    testData.push_back(data);

}