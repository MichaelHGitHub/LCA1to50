#include "header.h"

void PrepareTestData(vector<TD_I_S>& test_data)
{
    TD_I_S data = {};

    data.input = 5;
    data.output = "V";
    test_data.push_back(data);

    data.input = 10;
    data.output = "X";
    test_data.push_back(data);

    data.input = 50;
    data.output = "L";
    test_data.push_back(data);

    data.input = 100;
    data.output = "C";
    test_data.push_back(data);

    data.input = 500;
    data.output = "D";
    test_data.push_back(data);

    data.input = 100;
    data.output = "C";
    test_data.push_back(data);

    data.input = 3;
    data.output = "III";
    test_data.push_back(data);

    data.input = 4;
    data.output = "IV";
    test_data.push_back(data);

    data.input = 9;
    data.output = "IX";
    test_data.push_back(data);

    data.input = 58;
    data.output = "LVIII";
    test_data.push_back(data);

    data.input = 1994;
    data.output = "MCMXCIV";
    test_data.push_back(data);
}
