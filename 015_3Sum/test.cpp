#include "header.h"

void PrepareTestData(vector<TD_VI_VVI>& testData)
{
    TD_VI_VVI data;
    vector<int> input;
    vector<int> output_entry;
    vector<vector<int>> output;
    vector<vector<int>> null_result;

    input.clear();
    output.clear();
    input.assign({ -2, 0, 1, 1, 2 });
    data.input = input;

    output_entry.clear();
    output_entry.assign({ -2, 0, 2 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -2, 1, 1 });
    output.push_back(output_entry);

    data.output = output;

    testData.push_back(data);

    // Test case 1

    input.clear();
    output.clear();
    input.assign({ -1,0,1,2,-1,-4 });
    data.input = input;

    output_entry.clear();
    output_entry.assign({ -1,-1,2 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -1,0,1 });
    output.push_back(output_entry);

    data.output = output;

    testData.push_back(data);

    // Test case 2
    input.clear();
    output.clear();

    input.assign({});
    data.input = input;

    data.output = null_result;

    testData.push_back(data);

    // Test case 3
    input.clear();
    output.clear();

    input.assign({ 0 });
    data.input = input;

    data.output = null_result;

    testData.push_back(data);

    // Test case 4
    input.clear();
    output.clear();
    input.assign({ 0,0,0,0 });
    data.input = input;

    output_entry.clear();
    output_entry.assign({ 0,0,0 });
    output.push_back(output_entry);

    data.output = output;

    testData.push_back(data);

    // Test case 5
    input.clear();
    output.clear();
    input.assign({ -2,0,1,1,2 });
    data.input = input;

    output_entry.clear();
    output_entry.assign({ -2, 0, 2 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -2, 1, 1 });
    output.push_back(output_entry);

    data.output = output;

    // Test case 5
    input.clear();
    output.clear();
    input.assign({ -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4 });
    data.input = input;

    output_entry.clear();
    output_entry.assign({ -4, 0, 4 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -4, 1, 3 });
    output.push_back(output_entry);

    output_entry.clear();
    output_entry.assign({ -3, -1, 4 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -3, 0, 3 });
    output.push_back(output_entry);

    output_entry.clear();
    output_entry.assign({ -3, 1, 2 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -2, -1, 3 });
    output.push_back(output_entry);

    output_entry.clear();
    output_entry.assign({ -2, 0, 2 });
    output.push_back(output_entry);
    output_entry.clear();
    output_entry.assign({ -1, -1, 2 });
    output.push_back(output_entry);

    output_entry.clear();
    output_entry.assign({ -1, 0, 1 });
    output.push_back(output_entry);

    data.output = output;

    testData.push_back(data);
}