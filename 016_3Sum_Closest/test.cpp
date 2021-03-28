#include "header.h"

void PrepareTestData(vector<TD_VI_I_I>& testData)
{
    TD_VI_I_I data;

    data.input = { 1, 1, 1, 1 };
    data.input2 = 0;
    data.output = 3;
    testData.push_back(data);


    data.input = { -1, 2, 1, -4 };
    data.input2 = 1;
    data.output = 2;
    testData.push_back(data);

    data.input = { -1,2,1,-4 };
    data.input2 = 1;
    data.output = 2;
    testData.push_back(data);

    

    //data.input = ;
    //data.input2 = ;
    //data.output = ;
    //testData.push_back(data);


}