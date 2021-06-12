#include "header.h"

void PrepareTestData(vector<TD_S_S_B>& testData)
{
    TD_S_S_B data;

    data.input = "";
    data.input2 = "c*c*";
    data.output = true;
    testData.push_back(data);

    data.input = "bbab";
    data.input2 = "b*a*";
    data.output = false;
    testData.push_back(data);

    data.input = "abc";
    data.input2 = "abcd*";
    data.output = true;
    testData.push_back(data);

    data.input = "abc";
    data.input2 = "abcd*e*";
    data.output = true;
    testData.push_back(data);

    data.input = "abc";
    data.input2 = "ab*cd*";
    data.output = true;
    testData.push_back(data);

    data.input = "aa";
    data.input2 = "a*";
    data.output = true;
    testData.push_back(data);

    data.input = "ab";
    data.input2 = ".*c";
    data.output = false;
    testData.push_back(data);

    data.input = "aaa";
    data.input2 = "ab*a*c*a";
    data.output = true;
    testData.push_back(data);



    data.input = "pi";
    data.input2 = "p*.";
    data.output = true;
    testData.push_back(data);

    data.input = "mississippi";
    data.input2 = "mis*is*ip*.";
    data.output = true;
    testData.push_back(data);

    data.input = "aaa";
    data.input2 = "a*aa";
    data.output = true;
    testData.push_back(data);

    data.input = "aab";
    data.input2 = "a*ab";
    data.output = true;
    testData.push_back(data);

    data.input = "aaa";
    data.input2 = "a*a";
    data.output = true;
    testData.push_back(data);

    data.input = "aa";
    data.input2 = "b*a*c*a";
    data.output = true;
    testData.push_back(data);

    data.input = "aaa";
    data.input2 = "ab*a*c*a";
    data.output = true;
    testData.push_back(data);

    data.input = "aba";
    data.input2 = "a*ba";
    data.output = true;
    testData.push_back(data);

    data.input = "aasdfasdfasdfasdfas";
    data.input2 = "aasdf.*asdf.*asdf.*asdf.*s";
    data.output = true;
    testData.push_back(data);

    data.input = "aaa";
    data.input2 = "a*aaa";
    data.output = true;
    testData.push_back(data);

    data.input = "aaa";
    data.input2 = "a*a";
    data.output = true;
    testData.push_back(data);

    data.input = "aaa";
    data.input2 = "a*aaaa";
    data.output = false;
    testData.push_back(data);

    data.input = "aba";
    data.input2 = "a*ba";
    data.output = true;
    testData.push_back(data);



    data.input = "aab";
    data.input2 = "c*a*b";
    data.output = true;
    testData.push_back(data);

    data.input = "aa";
    data.input2 = "a";
    data.output = false;
    testData.push_back(data);

    data.input = "aa";
    data.input2 = "a*";
    data.output = true;
    testData.push_back(data);

    data.input = "ab";
    data.input2 = ".*";
    data.output = true;
    testData.push_back(data);

    data.input = "aab";
    data.input2 = "c*a*b";
    data.output = true;
    testData.push_back(data);

}