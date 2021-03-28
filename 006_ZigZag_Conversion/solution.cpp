#include "header.h"

// Form the 2 dimensional array
// When move foreward, increase row number,
// when move backward, decrease row number,
// when row == numRows or row == 0, change the 
// direction.I also fill in the empty characters, which can be
// skipped in solution2 with a little change. 

string convert(string s, int numRows)
{
    vector<vector<char>> zig_zag;

    for (int i = 0; i < numRows; i++)
    {
        zig_zag.push_back(vector<char>());
    }

    int row = 0;
    int col = 0;
    bool foreward = true;

    // Use a variable to calculate how many empty char we need to fill. 
    int round = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (foreward)
        {
            if (row < numRows)
            {
                // Fill in the empty chars, note where and how many 
                // empty char we need to fill. 
                int fill = col - round * (numRows - 1) - 1;
                for (int j = 0; j < fill; j++)
                {
                    zig_zag[row].push_back(' ');
                }

                zig_zag[row].push_back(s[i]);
                ++row;
            }
            else
            {
                // when row = numRows, need to rewind the string
                // by 1 to include the current char because it doesn't
                // get added in the array in this round.
                --i;
                foreward = false;
                row = numRows - 1;
            }
        }
        else
        {
            int fill = col - round * (numRows-1) - 1;
            if(row >= 0)
            {
                for (int j = 0; j < fill; j++)
                {
                    zig_zag[row].push_back(' ');
                }

                // In the following conditions, need to rewind the string
                // by 1 to include the current char in next round
                // because it doesn't get added in the array in this round.
                if (row == numRows - 1 || row == 0)
                {
                    --i;
                }
                else
                {
                    zig_zag[row].push_back(s[i]);
                }

                --row;
                ++col;
            }
            else
            {
                // When row = -1, need to rewind the string
                // by 1 to include the current char in next round
                // because it doesn't get added in the array in this round.
                --i;
                foreward = true;
                ++round;
                row = 0;
            }
        }
    }

    // Make the output string
    string result;
    for (int i = 0; i < zig_zag.size(); i++)
    {
        for (int j = 0; j < zig_zag[i].size(); j++)
        {
            if (zig_zag[i][j] != ' ')
            {
                result.append(1, zig_zag[i][j]);
            }
        }
    }

    return result;
}