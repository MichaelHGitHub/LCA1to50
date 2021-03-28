#include "header.h"

// Allocate an vector<string> to represent the rows 
// When move foreward, increase row number,
// when move backward, decrease row number,
// when row == numRows-1 or row == 0, change the 
// direction. No need to care about empty chars because we won't need
// to include in the result string.

string convert2(string s, int numRows)
{
    if (1 == numRows)
    {
        return s;
    }

    vector<string> zig_zag(numRows);

    int row = 0;
    bool foreward = true;
    for (int i = 0; i < s.length(); i++)
    {
        // Add the char to its row
        zig_zag[row].append(1, s[i]);

        // Change directon to move backward
        if (row == numRows - 1)
        {
            foreward = false;
        }

        // Change direction to move foreward
        if (0 == row)
        {
            foreward = true;
        }

        // Increase or decrease row depending on the direction
        row += foreward ? 1 : -1;
    }

    string result;
    for (int i = 0; i < zig_zag.size(); i++)
    {
        result.append(zig_zag[i]);
    }

    return result;
}