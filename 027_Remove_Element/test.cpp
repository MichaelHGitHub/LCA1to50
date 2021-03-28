#include "header.h"

void PrepareTestData(vector<TD_VI_I_I>& testData)
{
    TD_VI_I_I data;

    data.input = { 1 };
    data.input2 = 1;
    data.output = 0;
    testData.push_back(data);

    data.input = { 3,2,2,3 };
    data.input2 = 3;
    data.output = 2;
    testData.push_back(data);


    data.input = { 0,1,2,2,3,0,4,2 };
    data.input2 = 2;
    data.output = 5;
    testData.push_back(data);

}