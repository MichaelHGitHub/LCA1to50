#include "header.h"

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    double median = 0.0000;

    // An array to save merged elements
    vector<int> merged_nums;
    int merged_size = nums1.size() + nums2.size();

    // the median index in the merged array
    int median_index = merged_size / 2;

    // If the size is odd, median is the element exactly in the middle, 
    // if it is even, the median is:(merged[median_index] + merged[median_index -1]) /2
    int remaind = merged_size % 2;

    int index1 = 0;
    int index2 = 0;

    // Index1 + index2 = merged.size()
    while ((index1 + index2) < (median_index + 1))
    {
        if (index1 < nums1.size() && index2 < nums2.size())
        {
            if (nums1[index1] > nums2[index2])
            {
                merged_nums.push_back(nums2[index2]);
                index2++;
            }
            else
            {
                merged_nums.push_back(nums1[index1]);
                index1++;
            }
        }
        else if (index1 < nums1.size())
        {
            merged_nums.push_back(nums1[index1]);
            index1++;
        }
        else if (index2 < nums2.size())
        {
            merged_nums.push_back(nums2[index2]);
            index2++;
        }
    }

    // If the size is odd, median is the element exactly in the middle, 
    // if it is even, the median is:(merged[median_index] + merged[median_index -1]) /2
    if ((index1 + index2) == median_index + 1)
    {
        if (remaind > 0)
        {
            median = (double)merged_nums[median_index];
        }
        else
        {
            median = ((double)merged_nums[median_index] + (double)merged_nums[median_index - 1]) / 2;
        }
    }

    return median;

}