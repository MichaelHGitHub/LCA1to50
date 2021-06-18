#pragma once
#include <vector>
#include "..\common\common.h"

void PrepareTestData(vector<TD_VI_I_VVI>& testData);

vector<vector<int>> fourSum(vector<int>& nums, int target);

vector<vector<int>> fourSum_r(vector<int>& nums, int target);