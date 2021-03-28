#include "header.h"


void PrepareTestData(vector<TD_S_S_I>& testData)
{
    TD_S_S_I data;

    data.input = "baabbbbababbbabab";
    data.input2 = "abbab";
    data.output = -1;
    testData.push_back(data);

    data.input = "hello";
    data.input2 = "ll";
    data.output = 2;
    testData.push_back(data);

    data.input = "aaaaa";
    data.input2 = "bba";
    data.output = -1;
    testData.push_back(data);

    data.input = "";
    data.input2 = "";
    data.output = 0;
    testData.push_back(data);

    data.input = "baabbbbababbbabab";
    data.input2 = "abbab";
    data.output = -1;
    testData.push_back(data);
}