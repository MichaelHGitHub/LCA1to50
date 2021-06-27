#include "header.h"

void PrepareTestData(vector<TD_L_I_L>& testData)
{
    TD_L_I_L data = {};

    data.input = GenerateLinkedList({ 1,2,3,4,5 });
    data.input2 = 2;
    data.output = GenerateLinkedList({ 2,1,4,3,5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,3,4,5 });
    data.input2 = 3;
    data.output = GenerateLinkedList({ 3,2,1,4,5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,3,4,5 });
    data.input2 = 1;
    data.output = GenerateLinkedList({ 1,2,3,4,5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1});
    data.input2 = 1;
    data.output = GenerateLinkedList({ 1});
    testData.push_back(data);

}