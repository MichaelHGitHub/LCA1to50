#pragma once
#include "..\common\common.h"

void PrepareTestData(vector<TD_VVC_B>& testData);

bool isValidSudoku(vector<vector<char>>& board);
bool isValidSudoku2(vector<vector<char>>& board);

bool isValidSudoku_r(vector<vector<char>>& board);