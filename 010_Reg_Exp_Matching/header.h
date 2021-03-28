#pragma once
#include "..\common\common.h"

void PrepareTestData(vector<TD_S_S_B>& testData);

// Recursive with two pointer, no string copy needed
bool isMatch(string s, string p);

// Recursive, string copies are made in each recursive call
bool isMatch2(string s, string p);

// Non-recursive, a two dimension array is needed to save result 
// for chars at each position
bool isMatch3(string s, string p);