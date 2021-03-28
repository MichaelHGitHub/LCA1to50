#include "header.h"

// The follwoing implementation doesn't generate correct answer for all the cases although it
// it works for most. the idea is not right, keep it just for reference. 
bool isMatch_bak(string s, string p)
{
    bool result = false;

    size_t index_s = 0;
    size_t index_p = 0;
    int repeat_num = 0;
    char repeat_char = ' ';

    while (index_s < s.size() || index_p < p.size())
    {
        if (index_s < s.size() && index_p < p.size())
        {
            if ((index_p < p.size() - 1) && p.at(index_p + 1) == '*')
            {
                repeat_char = p.at(index_p);
                index_p++;
            }
            else if (p.at(index_p) == '*')
            {
                if ((index_p < p.size() - 1) && (s.at(index_s) == p.at(index_p + 1) || p.at(index_p + 1) == '.'))
                {
                    index_p++;
                }
                else if (s.at(index_s) == repeat_char || repeat_char == '.')
                {
                    repeat_num++;
                    index_s++;
                }
                else
                {
                    index_p++;
                }
            }
            else if (s.at(index_s) == p.at(index_p) || p.at(index_p) == '.')
            {
                if(p.at(index_p) != repeat_char && p.at(index_p) != '.')
                {
                    repeat_char = ' ';
                }

                // Non-repeating char
                index_s++;
                index_p++;
                repeat_num = 0;
            }
            else if (index_s > 1 && (repeat_char == s.at(index_s - 1) || repeat_char == '.') && repeat_num > 0)
            {
                repeat_num--;
                //index_p++;
                //index_s--;
            }
            else if (s.at(index_s) == repeat_char || repeat_char == '.')
            {
                repeat_num++;
                index_s++;
                index_p--;
            }
            else
            {
                // Don't match
                break;
            }
        }
        else if (index_p < p.size())
        {
            if ((index_p < p.size() - 1) && p.at(index_p + 1) == '*')
            {
                index_p++;
            }
            else if (p.at(index_p) == '*')
            {
                index_p++;
            }
            else if (index_s > 1 && (repeat_char == s.at(index_s -1) || repeat_char == '.' ) && repeat_num > 0)
            {
                repeat_num--;
                index_p++;
                //index_s--;

            }
            else
            {
                break;
            }
        }
        else
        {
            if (s.at(index_s) == repeat_char || repeat_char == '.')
            {
                repeat_num++;
                index_s++;
                index_p--;
            }
            else
            {
                break;
            }
        }
    }

    if (index_s >= s.size() && index_p >= p.size())
    {
        result = true;
    }

    return result;
}

//sameple()
//{
//    class Solution {
//        public boolean isMatch(String text, String pattern) {
//            boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
//            dp[text.length()][pattern.length()] = true;
//
//            for (int i = text.length(); i >= 0; i--) {
//                for (int j = pattern.length() - 1; j >= 0; j--) {
//                    boolean first_match = (i < text.length() &&
//                        (pattern.charAt(j) == text.charAt(i) ||
//                            pattern.charAt(j) == '.'));
//                    if (j + 1 < pattern.length() && pattern.charAt(j + 1) == '*') {
//                        dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
//                    }
//                    else {
//                        dp[i][j] = first_match && dp[i + 1][j + 1];
//                    }
//                }
//            }
//            return dp[0][0];
//        }
//    }
//}