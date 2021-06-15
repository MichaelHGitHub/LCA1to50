#include <unordered_map>
#include "header.h"

static void helper(vector<string>& result, string& letters, string& digits, int pos);

unordered_map<char, string> dic = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

vector<string> letterCombinations_r(string digits)
{
    vector<string> result;
    string letters(digits.length(), ' ');
    helper(result, letters, digits, 0);

    return result;
}


void helper(vector<string>& result, string& letters, string& digits, int pos)
{
    if (pos == digits.length())
    {
        if (letters.length() > 0)
        {
            result.push_back(letters);
        }
        return;
    }

    string s = dic[digits[pos]];
    for (int i = 0; i < s.length(); i++)
    {
        letters[pos] = s[i];
        helper(result, letters, digits, pos + 1);
    }
}
