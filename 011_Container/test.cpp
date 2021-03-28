#include "header.h"



void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data_element = {};
    vector<int> input;

    input.assign({ 1, 8, 6, 2, 5, 4, 8, 3, 7 });
    data_element.input = input;
    data_element.output = 49;
    testData.push_back(data_element);

    input.clear();
    input.assign({ 1, 1 });
    data_element.input = input;
    data_element.output = 1;
    testData.push_back(data_element);

    input.clear();
    input.assign({ 4, 3, 2, 1, 4 });
    data_element.input = input;
    data_element.output = 16;
    testData.push_back(data_element);

    input.clear();
    input.assign({ 1, 2, 1 });
    data_element.input = input;
    data_element.output = 2;
    testData.push_back(data_element);

}