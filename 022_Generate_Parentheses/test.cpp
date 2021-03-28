#include "header.h"

void PrepareTestData(vector<TD_I_VS>& testData)
{
    TD_I_VS data;

    data.input = 1;
    data.output = { "()" };

    testData.push_back(data);

    data.input = 2;
    data.output = { "(())","()()" };

    testData.push_back(data);

    data.input = 3;
    data.output= { "((()))","(()())","(())()","()(())","()()()" };

    testData.push_back(data);

    data.input = 4;
    data.output = { "(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()", "()()(())", "()()()()" };
                    
    testData.push_back(data);


    


}