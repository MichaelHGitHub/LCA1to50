#include <vector>
#include "header.h"

bool isMatch3(string s, string p)
{
    vector<vector<bool>> results;
    for (int i = 0; i < s.length() + 1; i++)
    {
        vector<bool> column(p.length() + 1, false);
        results.push_back(column);
    }
    results[s.length()][p.length()] = true;

    if (p.empty())
    {
        return s.empty();
    }

    // Note: i starts from s.length() instead of (s.length() -1), this assigns 
    // value to results[s.length()][p.length()-1 ... 0], these values are crutial
    // to check cases involve x* at the end of pattern. 
    for (int i = s.length(); i >= 0; i--)
    {
        for (int j = p.length() - 1; j >= 0; j--)
        {
            bool first_match = (i < s.length() && (s.at(i) == p.at(j) || p.at(j) == '.'));

            if (j < p.length() - 1 && p.at(j + 1) == '*')
            {
                if (results[i][j+2])
                {
                    results[i][j] = true;
                }
                else if(first_match && results[i+1][j])
                {
                    results[i][j] = true;
                }
                else
                {
                    results[i][j] = false;
                }
            }
            else
            {
                if (first_match && results[i + 1][j + 1])
                {
                    results[i][j] = true;
                }
                else
                {
                    results[i][j] = false;
                }
            }
        }
    }

    return results[0][0];

}