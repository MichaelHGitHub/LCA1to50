#include <unordered_set>
#include "header.h"

static bool canFill(vector<vector<char>>& board, int row, int col, char c);
static bool fillSudoku(vector<vector<char>>& board, int row, int col);

void solveSudoku_r(vector<vector<char>>& board)
{
    fillSudoku(board, 0, 0);
}

bool canFill(vector<vector<char>>& board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c || board[i][col] == c)
        {
            return false;
        }
    }

    int r = row / 3 * 3;
    int l = col / 3 * 3;
    for (int i = r; i < r + 3; i++)
    {
        for (int j = l; j < l + 3; j++)
        {
            if (board[i][j] == c)
            {
                return false;
            }
        }
    }
    return true;
}


bool fillSudoku(vector<vector<char>>& board, int i, int j)
{
    if (i >= 9)
    {
        return true;
    }

    if (j >= 9)
    {
        return fillSudoku(board, i + 1, 0);
    }

    if (board[i][j] == '.')
    {
        for (char k = '1'; k <= '9'; k++)
        {
            if (canFill(board, i, j, k))
            {
                board[i][j] = k;
                if (fillSudoku(board, i, j + 1))
                {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }
    else
    {
        return fillSudoku(board, i, j + 1);
    }
    return false;
}