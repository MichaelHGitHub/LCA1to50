#include "header.h"

double findMedianSortedArrays_r(vector<int>& nums1, vector<int>& nums2) {

    int size1 = nums1.size();
    int size2 = nums2.size();
    int size_m = size1 + size2;

    int pre = 0, cur = 0;
    int i1 = 0, i2 = 0;

    int mid = size_m / 2;
    bool odd = size_m % 2 > 0;

    while (i1 < size1 || i2 < size2)
    {
        if (i1 < size1 && i2 < size2)
        {
            pre = cur;
            if (nums1[i1] < nums2[i2])
            {
                cur = nums1[i1];
                ++i1;
            }
            else
            {
                cur = nums2[i2];
                ++i2;
            }
        }
        else if (i1 < size1)
        {
            pre = cur;
            cur = nums1[i1];
            ++i1;
        }
        else
        {
            pre = cur;
            cur = nums2[i2];
            ++i2;
        }

        // check mid + 1 because index is increased before its corresponding value is checked.
        if (i1 + i2 == mid + 1)
        {
            if (odd)
            {
                return (double)cur;
            }
            else
            {
                return ((double)pre + cur) / 2;
            }
        }
    }

    return -1;
}