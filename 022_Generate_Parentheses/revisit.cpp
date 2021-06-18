#include "header.h"

static bool isValid(string& s)
{
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            ++counter;
        }
        else
        {
            --counter;
        }
        if (counter < 0)
        {
            return false;
        }
    }
    return counter == 0;
}

void helper(vector<string>& res, string& s, int num, int count)
{
    if (count == num)
    {
        if (isValid(s))
        {
            res.push_back(s);
        }

        return;
    }
    s[count] = '(';
    helper(res, s, num, count + 1);
    s[count] = ')';
    helper(res, s, num, count + 1);
}

vector<string> generateParenthesis_r(int n)
{
    vector<string> result;
    string s(2 * n, ' ');
    helper(result, s, 2*n, 0);

    return result;
}