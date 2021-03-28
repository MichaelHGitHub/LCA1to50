#include "header.h"


void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 0 };
    data.output = 0;
    testData.push_back(data);

    data.input = { 5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5 };
    data.output = 5;
    testData.push_back(data);

    data.input = { 2, 1, 4, 3 };
    data.output = 2;
    testData.push_back(data);

    data.input = { 1, 1, 3 };
    data.output = 2;
    testData.push_back(data);

    data.input = { 2,3,1,1,4 };
    data.output = 2;
    testData.push_back(data);

    data.input = { 1,3 };
    data.output = 1;
    testData.push_back(data);



    data.input = { 2,3,0,1,4 };
    data.output = 2;
    testData.push_back(data);
}