#include "header.h"

void PrepareTestData(vector<TD_VI_VVI>& testData)
{
    TD_VI_VVI data;

    data.input = { 0,1 };
    data.output = { {0,1} ,{1,0} };
    testData.push_back(data);

    data.input = { 2,3 };
    data.output = { {2,3} ,{3,2} };
    testData.push_back(data);

    data.input = { 1,2,3 };
    data.output = { {1,2,3} ,{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1} };
    testData.push_back(data);

    data.input = { 1 };
    data.output = { {1} };
    testData.push_back(data);

}