#include <map>
#include "header.h"

vector<string> combineTwoSet(vector<string>& s1, vector<string>& s2);


vector<string> letterCombinations(string digits)
{
    vector<string> result;

    map<char, vector<string>> dictionary;
    dictionary['2'] = { "a", "b", "c" };
    dictionary['3'] = { "d", "e", "f" };
    dictionary['4'] = { "g", "h", "i" };
    dictionary['5'] = { "j", "k", "l" };
    dictionary['6'] = { "m", "n", "o" };
    dictionary['7'] = { "p", "q", "r", "s" };
    dictionary['8'] = { "t", "u", "v" };
    dictionary['9'] = { "w", "x", "y", "z" };

    for (int i = 0; i < digits.length(); i++)
    {
        vector<string> current_letters = dictionary[digits.at(i)];

        result = combineTwoSet(result, current_letters);
    }


    return result;
}

vector<string> combineTwoSet(vector<string>& s1, vector<string>& s2)
{
    if (0 == s1.size())
    {
        return s2;
    }

    vector<string> result;

    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            result.push_back(s1[i] + s2[j]);
        }
    }

    return result;
}
