#include "header.h"



void PrepareTestData(vector<TD_S_I>& testData)
{
    TD_S_I data_element = {};

    data_element.input = "42";
    data_element.output = 42;
    testData.push_back(data_element);

    data_element.input = "   -42";
    data_element.output = -42;
    testData.push_back(data_element);

    data_element.input = "4193 with words";
    data_element.output = 4193;
    testData.push_back(data_element);

    data_element.input = "words and 987";
    data_element.output = 0;
    testData.push_back(data_element);

    data_element.input = "-91283472332";
    data_element.output = -2147483648;
    testData.push_back(data_element);

    data_element.input = "-x8";
    data_element.output = 0;
    testData.push_back(data_element);
}



