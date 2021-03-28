#include "header.h"

void PrepareTestData(vector<TD_VI_I_VVI>& testData)
{
    TD_VI_I_VVI data;
    vector<int> input;
    vector<int> output_entry;
    vector<vector<int>> output;
    vector<vector<int>> null_result;

    // Test case 1
    data.input = { 1,0,-1,0,-2,2 };
    data.input2 = 0;

    output.clear();

    output_entry.clear();
    output_entry.assign({ -2,-1,1,2 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -2,0,0,2 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -1, 0, 0, 1 });
    output.push_back(output_entry);

    data.output = output;

    testData.push_back(data);

    // Test case 2

    data.input = {};
    data.input2 = 0;
    data.output = null_result;

    testData.push_back(data);

    // Test case 3

    data.input = { 0, 0, 0, 0 };
    data.input2 = 0;

    output.clear();
    output_entry.clear();
    output_entry.assign({ 0, 0, 0, 0 });
    output.push_back(output_entry);

    data.output = output;

    testData.push_back(data);

    // Test case 3

    data.input = { -1, 1, -1, 1 };
    data.input2 = 0;

    output.clear();
    output_entry.clear();
    output_entry.assign({ -1, -1, 1, 1 });
    output.push_back(output_entry);

    data.output = output;

    testData.push_back(data);

}