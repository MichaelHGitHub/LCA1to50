#include "header.h"

// For each square of area, move the out edge elements clockwise by 
// (last_row - first_row). When an element is moving along its
// row(colume is changing) and its calculated colume index gets
// beyond the boundary, move its row index to make up the rest of the
// steps. Apply similar logic for an element when moving along its colume.
//
void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    int first_row = 0;

    // Steps each element needs to move clockwise, starts with (n-1) for
    // the first iteration, then decrease by 2 after each iteration.
    int steps = n - 1;

    while (steps > 0)
    {
        int first_col = first_row;
        int last_row = n - first_row - 1;
        int last_col = n - first_col - 1;

        // Start moving elements, Note: the last element in a row will be 
        // holding the first element, which is processed when i = first_col, 
        // so the last element shouldn't go through the loop.
        for (int i = first_col; i < last_col; i++)
        {
            // the offset by which the element's row or colum index should
            // move in order to reach the required steps. 
            int offset = i + steps - last_col;

            int temp = matrix[first_row][i];
            matrix[first_row][i] = matrix[last_row - offset][first_col];
            matrix[last_row - offset][first_col] = matrix[last_row][last_col - offset];
            matrix[last_row][last_col - offset] = matrix[first_row + offset][last_col];
            matrix[first_row + offset][last_col] = temp;
        }

        // Next row
        first_row++;

        // Since first and last row/colum both increase by 1
        // the steps will decrease by 2
        steps -= 2;
    }
}