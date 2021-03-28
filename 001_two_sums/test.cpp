#include "header.h"

void PrepareTestData(vector<TD_VI_I_VI>& testData)
{
    TD_VI_I_VI data_element = {};
    vector<int> input;
    vector<int> output;

    input.assign({ 2, 7, 11, 15 });
    output.assign({ 0, 1 });
    data_element.input = input;
    data_element.input2 = 9;
    data_element.output = output;
    testData.push_back(data_element);

    input.clear();
    output.clear();
    input.assign({ 3,2,4 });
    output.assign({ 1,2 });
    data_element.input = input;
    data_element.input2 = 6;
    data_element.output = output;
    testData.push_back(data_element);

    input.clear();
    output.clear();
    input.assign({ 3,3 });
    output.assign({ 0,1 });
    data_element.input = input;
    data_element.input2 = 6;
    data_element.output = output;
    testData.push_back(data_element);

    input.clear();
    output.clear();
    input.assign({ 3, 9, 6, 2, 8 });
    output.assign({ 0, 2 });
    data_element.input = input;
    data_element.input2 = 9;
    data_element.output = output;
    testData.push_back(data_element);

}