#include "header.h"

//
// Algorithm: use two pointers, anchor the larger side and move the less side inwards,
//          for each step, calculate the area and save the larger one. 
//          key trick: the skipped ones are smaller than the ones checked. why???
//
int maxArea(vector<int>&height)
{
    if (height.size() < 2)
    {
        return 0;
    }

    int area = 0;

    int left = 0;
    int right = height.size() - 1;

    while (right > left)
    {
        int current_area = min(height[left], height[right]) * (right - left);

        if (area < current_area)
        {
            area = current_area;
        }

        if (height[left] > height[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return area;
}