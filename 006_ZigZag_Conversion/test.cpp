#include "header.h"

void PrepareTestData(vector<TD_S_I_S>& testData)
{
    TD_S_I_S data;

    data.input = "AB";
    data.input2 = 1;
    data.output = "AB";
    testData.push_back(data);

    data.input = "PAYPALISHIRING";
    data.input2 = 3;
    data.output = "PAHNAPLSIIGYIR";
    testData.push_back(data);

    data.input = "PAYPALISHIRING";
    data.input2 = 4;
    data.output = "PINALSIGYAHRPI";
    testData.push_back(data);

    data.input = "A";
    data.input2 = 1;
    data.output = "A";
    testData.push_back(data);

}