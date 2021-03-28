#include "header.h"

void PrepareTestData(vector<TD_VVI_VVI>& testData)
{
    TD_VVI_VVI data;

    data.input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    data.output = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    testData.push_back(data);

    data.input = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    data.output = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    testData.push_back(data);

    data.input = {{1}};
    data.output = {{1}};
    testData.push_back(data);

    data.input = {{1, 2}, {3, 4}};
    data.output = {{3, 1}, {4, 2}};
    testData.push_back(data);
}