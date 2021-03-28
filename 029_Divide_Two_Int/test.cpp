#include "header.h"

void PrepareTestData(vector<TD_I_I_I>& testData)
{
    TD_I_I_I data;

    
        

    data.input = -1010369383;
    data.input2 = -2147483648;
    data.output = 0;
    testData.push_back(data);

    data.input = -2147483648;
    data.input2 = 1;
    data.output = -2147483648;
    testData.push_back(data);

    data.input = -2147483648;
    data.input2 = -1;
    data.output = 2147483647;
    testData.push_back(data);

    data.input = -2147483648;
    data.input2 = 2;
    data.output = -1073741824;
    testData.push_back(data);

    data.input = 10;
    data.input2 = 3;
    data.output = 3;
    testData.push_back(data);

    data.input = -2147483648;
    data.input2 = -2147483648;
    data.output = 1;
    testData.push_back(data);

    data.input = 1004958205;
    data.input2 = -2137325331;
    data.output = 0;
    testData.push_back(data);

    data.input = 2147483647;
    data.input2 = 1;
    data.output = 2147483647;
    testData.push_back(data);

    data.input = -2147483648;
    data.input2 = -1;
    data.output = 2147483647;
    testData.push_back(data);

    data.input = 7;
    data.input2 = -3;
    data.output = -2;
    testData.push_back(data);

    data.input = 0;
    data.input2 = 1;
    data.output = 0;
    testData.push_back(data);

}