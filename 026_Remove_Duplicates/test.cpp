#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = {};
    data.output = 0;
    testData.push_back(data);

    data.input = { 1,1,2 };
    data.output = 2;
    testData.push_back(data);

    data.input = { 1, 2, 3, 4, 5, 6 };
    data.output = 6;
    testData.push_back(data);

    data.input = { 0,0,1,1,1,2,2,3,3,4 };
    data.output = 5;
    testData.push_back(data);


}