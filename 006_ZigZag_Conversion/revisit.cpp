#include "header.h"

// Allocate an vector<string> to represent the rows 
// When move foreward, increase row number,
// when move backward, decrease row number,
// when row == numRows-1 or row == 0, change the 
// direction. No need to care about empty chars because we won't need
// to include in the result string.

string convert_r(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }

    vector<vector<char>> v(numRows, vector<char>());

    int row = 0;
    int step = 0;

    for (int i = 0; i < s.length(); i++)
    {
        v[row].push_back(s[i]);

        if (row == 0)
        {
            step = 1;
        }
        else if (row == numRows - 1)
        {
            step = -1;
        }

        row += step;
    }

    string result;

    for (int i = 0; i < numRows; i++)
    {
        result.append(v[i].begin(), v[i].end());
    }

    return result;
}