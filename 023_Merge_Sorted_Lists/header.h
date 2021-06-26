#pragma once
#include <vector>
#include "..\common\common.h"

void PrepareTestData(vector<TD_VL_L>& testData);

ListNode* mergeKLists(vector<ListNode*>& lists);

ListNode* mergeKLists_r(vector<ListNode*>& lists);