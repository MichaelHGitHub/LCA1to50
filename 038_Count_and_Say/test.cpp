#include "header.h"

void PrepareTestData(vector<TD_I_S>& testData)
{
    TD_I_S data;

    data.input = 1;
    data.output = "1";
    testData.push_back(data);

    data.input = 2;
    data.output = "11";
    testData.push_back(data);

    data.input = 3;
    data.output = "21";
    testData.push_back(data);

    data.input = 4;
    data.output = "1211";
    testData.push_back(data);

    data.input = 10;
    data.output = "13211311123113112211";
    testData.push_back(data);
}