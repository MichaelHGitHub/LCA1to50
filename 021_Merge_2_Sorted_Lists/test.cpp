#include "header.h"

void PrepareTestData(vector<TD_L_L_L>& testData)
{
    TD_L_L_L data = {};

    data.input = GenerateLinkedList({ 1, 2, 4 });
    data.input2 = GenerateLinkedList({ 1,3,4 });
    data.output = GenerateLinkedList({ 1,1,2,3,4,4 });
    testData.push_back(data);


    data.input = GenerateLinkedList({});
    data.input2 = GenerateLinkedList({});
    data.output = GenerateLinkedList({});
    testData.push_back(data);

    data.input = GenerateLinkedList({});
    data.input2 = GenerateLinkedList({0});
    data.output = GenerateLinkedList({0});
    testData.push_back(data);
    
}