#include "header.h"


void PrepareTestData(vector<TD_VI_I_I>& testData)
{
    TD_VI_I_I data;

    data.input = { 1, 3 };
    data.input2 = 0;
    data.output = -1;
    testData.push_back(data);

    data.input = { 4,5,6,7,0,1,2 };
    data.input2 = 0;
    data.output = 4;
    testData.push_back(data);

    data.input = { 4,5,6,7,0,1,2 };
    data.input2 = 3;
    data.output = -1;
    testData.push_back(data);

    data.input = {1};
    data.input2 = 0;
    data.output = -1;
    testData.push_back(data);

}