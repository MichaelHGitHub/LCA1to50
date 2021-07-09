#include "header.h"

void rotate_r(vector<vector<int>>& matrix)
{
    int left = 0, right = matrix.size() - 1;
    int upper = 0, bottom = matrix[0].size() - 1;

    int to_be_moved = 0;
    int saved = 0;

    while (upper < bottom)
    {
        for (int i = left; i < right; i++)
        {
            to_be_moved = matrix[upper][i];
            saved = matrix[upper + (i - left)][right];
            matrix[upper + (i - left)][right] = to_be_moved;

            to_be_moved = saved;
            saved = matrix[bottom][right - (i - left)];
            matrix[bottom][right - (i - left)] = to_be_moved;

            to_be_moved = saved;
            saved = matrix[bottom - (i - left)][left];
            matrix[bottom - (i - left)][left] = to_be_moved;

            to_be_moved = saved;
            matrix[upper][i] = to_be_moved;
        }

        ++upper;
        --bottom;
        ++left;
        --right;
    }
}