#include "header.h"

void PrepareTestData(vector<TD_VL_L>& testData)
{
    TD_VL_L data;

    vector<ListNode*> input_entry;
    input_entry.push_back(GenerateLinkedList({ 1,4,5 }));
    input_entry.push_back(GenerateLinkedList({ 1,3,4 }));
    input_entry.push_back(GenerateLinkedList({ 2,6 }));
    data.input = input_entry;
    data.output = GenerateLinkedList({ 1,1,2,3,4,4,5,6 });
    testData.push_back(data);

    data.input = vector<ListNode*>();
    data.output = nullptr;
    testData.push_back(data);

    data.input = vector<ListNode*>(1, nullptr);
    data.output = nullptr;
    testData.push_back(data);

}