#include "header.h"

void PrepareTestData(vector<TD_S_I>& test_data)
{
    TD_S_I data;

    data.input = "III";
    data.output = 3;
    test_data.push_back(data);

    data.input = "IV";
    data.output = 4;
    test_data.push_back(data);

    data.input = "IX";
    data.output = 9;
    test_data.push_back(data);

    data.input = "LVIII";
    data.output = 58;
    test_data.push_back(data);

    data.input = "MCMXCIV";
    data.output = 1994;
    test_data.push_back(data);

}
