#include "header.h"

void PrepareTestData(vector<TD_VI_I_VVI>& testData)
{
    TD_VI_I_VVI data;

    data.input = { 3, 5, 8 };
    data.input2 = 11;
    data.output = { {3, 3, 5} ,{3, 8} };
    testData.push_back(data);

    data.input = { 2,3,6,7 };
    data.input2 = 7;
    data.output = { {2,2,3} ,{7} };
    testData.push_back(data);

    data.input = { 2,3,5 };
    data.input2 = 8;
    data.output = { {2,2,2,2} ,{2,3,3},{3,5} };
    testData.push_back(data);

    data.input = { 2 };
    data.input2 = 1;
    data.output = {};
    testData.push_back(data);

    data.input = { 1 };
    data.input2 = 1;
    data.output = { {1} };
    testData.push_back(data);

    data.input = { 1 };
    data.input2 = 2;
    data.output = { {1, 1} };
    testData.push_back(data);

}