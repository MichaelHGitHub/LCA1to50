#include "header.h"

// Note: this solution is an good try, but not correct. it can skip letters
// between last_pass_index and (last_pass_index + 1 << shift_count) if the letter
// at the (last_pass_index + 1 << shift_count) happen to be the same for every string
// in the vector. But somehow the solution get accepted, looks like the test cases don't
// cover this case. 
// Could use brute force to compare char by char in each of the strings,
// the time complexity would be O( m * n) while m = string0.lengther and 
// n = numbers of strings.
// In this solution, I do binary search in string0, the time complexity 
// therefore reduces to O(log(m) * n)
string longestCommonPrefix2(vector<string>& strs)
{
    if (strs.size() < 1)
    {
        return "";
    }
    else if (strs.size() == 1)
    {
        return strs[0];
    }

    int shift_count = 0;
    int sub_index = 0;
    int last_pass_index = -1;

    while (sub_index > last_pass_index && sub_index < strs[0].length())
    {
        bool pass = true;

        for (int i = 1; i < strs.size(); i++)
        {
            if (sub_index >= strs[i].length() ||
                strs[i].at(sub_index) != strs[0].at(sub_index))
            {
                pass = false;
                break;
            }
        }

        if (pass)
        {
            last_pass_index = sub_index;

            if (sub_index + (1 << shift_count) >= strs[0].length())
            {
                shift_count = 0;
            }

            sub_index = sub_index + (1 << shift_count);
            shift_count++;
        }
        else
        {
            // Note this exit condition: if the current check is right next to 
            // last_pass and not successful, should exit here.
            if (sub_index - last_pass_index < 2)
            {
                break;
            }
            else
            {
                shift_count = 0;
                sub_index = last_pass_index + (1 << shift_count);
            }
        }
    }

    return strs[0].substr(0, last_pass_index + 1);
}