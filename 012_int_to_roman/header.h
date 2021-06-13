#pragma once
#include <string>
#include "..\common\common.h"

void PrepareTestData(vector<TD_I_S>& test_data);
string intToRoman(int num);
string convertNumToRomanLetter(int digit, int multiper);
string convertNumToRomanLetter2(int digit, int multiper);

string intToRoman_r(int num);