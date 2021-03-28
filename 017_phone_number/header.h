#pragma once
#include <vector>
#include <string>
#include "..\common\common.h"

void PrepareTestData(vector<TD_S_VS>& testData);


//Given a string containing digits from 2 - 9 inclusive, return all possible
//letter combinations that the number could represent.Return the answer in 
//any order.
//Constraints:
//
//0 <= digits.length <= 4
//digits[i] is a digit in the range['2', '9'].
vector<string> letterCombinations(string digits);