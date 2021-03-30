#include "header.h"

double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    // Since j = (m+n+1)/2 - i while (0 <= i <= m),
    // Have to make sure that m < n so that j won't be nagtive value
    if (m > n)
    {
        return findMedianSortedArrays2(nums2, nums1);
    }

    double med = 0.00;

    // Here is size, not index, it makes sense to add 1;
    int half_length = (m + n + 1) / 2;

    int i_min = 0;
    int i_max = m;

    // Why need to proceed when i_min == i_max?
    while (i_min <= i_max)
    {
        int i = (i_min + i_max) / 2;

        // Q: Why j is fomulated this way?
        // instead of (m + n) / 2 - i
        int j = half_length - i;

        if (i < i_max && nums2[j - 1] > nums1[i])
        {
            i_min = i + 1;
        }
        else if (i > i_min && nums1[i - 1] > nums2[j])
        {
            i_max = i - 1;
        }
        else
        {
            // Found i
            int max_left = 0;

            if (i == 0)
            {
                max_left = nums2[j - 1];
            }
            else if (j == 0)
            {
                max_left = nums1[i - 1];
            }
            else
            {
                max_left = max(nums1[i - 1], nums2[j - 1]);
            }

            if ((m + n) % 2 == 1)
            {
                // Q: Why max_left and not the one behind?
                med = max_left;
            }
            else
            {
                int min_right = 0;

                if (i == m)
                {
                    min_right = nums2[j];
                }
                else if (j == n)
                {
                    min_right = nums1[i];
                }
                else
                {
                    min_right = min(nums1[i], nums2[j]);
                }

                med = ((double)max_left + (double)min_right) / 2;
            }

            break;
        }
    }

    return med;
}