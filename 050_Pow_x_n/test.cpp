#include "header.h"


void PrepareTestData(vector<TD_D_I_D>& testData)
{
    TD_D_I_D data;

    // MS compiler gets the input as 2.1000000001, 
    // there for , the result is not expected. no sure
    // why this is the case.
    data.input = 2.1000000000;
    data.input2 = 3;
    data.output = 9.26100;
    testData.push_back(data);

    data.input = -3.00000;
    data.input2 = 1;
    data.output = -3.00000;
    testData.push_back(data);

    data.input = 2.00000;
    data.input2 = -1;
    data.output = 0.50000;
    testData.push_back(data);

    data.input = -1.00000;
    data.input2 = -2147483648;
    data.output = 1.00000;
    testData.push_back(data);

    data.input = 1.00000;
    data.input2 = -2147483648;
    data.output = 1.00000;
    testData.push_back(data);

    data.input = 2.00000;
    data.input2 = -2147483648;
    data.output = 0.00000;
    testData.push_back(data);

    data.input = 2.00000;
    data.input2 = 10;
    data.output = 1024.00000;
    testData.push_back(data);

    data.input = 2.00000;
    data.input2 = -2;
    data.output = 0.25000;
    testData.push_back(data);

}