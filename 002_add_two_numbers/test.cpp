#include "header.h"

void PrepareTestData(vector<TD_L_L_L>& testData)
{
    TD_L_L_L data;

    data.input = GenerateLinkedList({ 9, 9, 9, 9, 9, 9, 9 });
    data.input2 = GenerateLinkedList({ 9, 9, 9, 9 });
    data.output = GenerateLinkedList({ 8, 9, 9, 9, 0, 0, 0, 1 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 2, 4, 3 });
    data.input2 = GenerateLinkedList({ 5, 6, 4 });
    data.output = GenerateLinkedList({ 7,0,8 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 0 });
    data.input2 = GenerateLinkedList({ 0 });
    data.output = GenerateLinkedList({ 0 });
    testData.push_back(data);
}

