#include "header.h"


void PrepareTestData(vector<TD_S_B>& testData)
{
    TD_S_B data = {};

    data.input = "()";
    data.output = true;
    testData.push_back(data);

    data.input = "()[]{}";
    data.output = true;
    testData.push_back(data);


    data.input = "(]";
    data.output = false;
    testData.push_back(data);

    data.input = "([)]";
    data.output = false;
    testData.push_back(data);

    data.input = "{[]}";
    data.output = true;
    testData.push_back(data);
}