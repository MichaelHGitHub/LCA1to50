#include "header.h"

void PrepareTestData(vector<TD_S_VS>& testData)
{
    TD_S_VS data;

    data.input = "23";
    data.output = { "ad","ae","af","bd","be","bf","cd","ce","cf" };
    testData.push_back(data);

    data.input = "";
    data.output = {};
    testData.push_back(data);

    data.input = "2";
    data.output = { "a","b","c" };
    testData.push_back(data);

}
