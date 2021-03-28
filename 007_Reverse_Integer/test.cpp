
#include "header.h"



void PrepareTestData(vector<TD_I_I>& testData)
{
    TD_I_I data_element = {};

    data_element.input = 123;
    data_element.output = 321;
    testData.push_back(data_element);

    data_element.input = -123;
    data_element.output = -321;
    testData.push_back(data_element);

    data_element.input = 120;
    data_element.output = 21;
    testData.push_back(data_element);

    data_element.input = 0;
    data_element.output = 0;
    testData.push_back(data_element);

    data_element.input = 1534236469;
    data_element.output = 0;
    testData.push_back(data_element);

    data_element.input = -2147483412;
    data_element.output = -2143847412;
    testData.push_back(data_element);

    data_element.input = 21789;
    data_element.output = 98712;
    testData.push_back(data_element);

    data_element.input = -33765;
    data_element.output = -56733;
    testData.push_back(data_element);
}