#include "header.h"

int maxArea_r(vector<int>& height)
{
    int result = 0;
    int i = 0;
    int j = height.size() - 1;

    while (i < j)
    {
        result = max(result, (j - i) * min(height[i], height[j]));

        if (height[i] > height[j])
        {
            --j;
        }
        else
        {
            ++i;
        }
    }

    return result;
}