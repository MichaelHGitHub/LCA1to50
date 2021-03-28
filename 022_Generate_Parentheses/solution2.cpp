#include <stack>
#include "header.h"

vector<string> generateParenthesis2(int n)
{
    vector<string> result;

    if (n == 0)
    {
        result.push_back("");
    }
    else
    {
        // make up the parenthese with left "(" + part + ")" + right
        // length of right part is c, length of left is (n -c -1),
        // c=[0,n)
        for (int c = 0; c < n; c++)
        {

            vector<string> left = generateParenthesis2(n - c - 1);
            vector<string> right = generateParenthesis2(c);

            for (int i = 0; i < left.size(); i++)
            {
                for (int j = 0; j < right.size(); j++)
                {
                    string s = "(" + left[i] + ")" + right[j];
                    result.push_back(s);
                }
            }
        }
    }

    return result;
}