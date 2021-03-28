#include "header.h"

void PrepareTestData(vector<TD_S_S_S>& testData)
{
    TD_S_S_S data;

    data.input = "2";
    data.input2 = "3";
    data.output = "6";
    testData.push_back(data);

    data.input = "123456789";
    data.input2 = "987654321";
    data.output = "121932631112635269";
    testData.push_back(data);

    data.input = "3";
    data.input2 = "456";
    data.output = "1368";
    testData.push_back(data);

    data.input = "23";
    data.input2 = "456";
    data.output = "10488";
    testData.push_back(data);

    data.input = "123";
    data.input2 = "456";
    data.output = "56088";
    testData.push_back(data);

    data.input = "0";
    data.input2 = "345";
    data.output = "0";
    testData.push_back(data);

}