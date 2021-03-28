#include "header.h"




void PrepareTestData(vector<TD_L_L_L>& testData)
{
    TD_L_L_L data = {};

    data.input = GenerateLinkedList({ 1, 2, 3, 4 });
    data.input2 = GenerateLinkedList({ 1, 2, 3, 4 });
    data.output = GenerateLinkedList({ 2,1,4,3 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ });
    data.input2 = GenerateLinkedList({ });
    data.output = GenerateLinkedList({ });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1 });
    data.input2 = GenerateLinkedList({ 1 });
    data.output = GenerateLinkedList({ 1 });
    testData.push_back(data);

}