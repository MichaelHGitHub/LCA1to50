#include "header.h"

void PrepareTestData(vector<TD_S_I>& testData)
{
    TD_S_I data_element = {};


    data_element.input = "abcad";
    data_element.output = 4;
    testData.push_back(data_element);

    data_element.input = "a";
    data_element.output = 1;
    testData.push_back(data_element);

    data_element.input = "au";
    data_element.output = 2;
    testData.push_back(data_element);

    data_element.input = "abcabcbb";
    data_element.output = 3;
    testData.push_back(data_element);

    data_element.input = "bbbbb";
    data_element.output = 1;
    testData.push_back(data_element);

    data_element.input = "pwwkew";
    data_element.output = 3;
    testData.push_back(data_element);

    data_element.input = "";
    data_element.output = 0;
    testData.push_back(data_element);
}