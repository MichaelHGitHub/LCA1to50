#include "header.h"

int reverseInt(int x)
{
    int temp = 0;
    int max = 0x7FFFFFFF;
    int min = 0x80000000;

    while (x)
    {
        int remain = x % 10;

        // check if beyond the upper boundery
        // if the value is larger than INT32_MAX / 10 ,
        // value * 10 will definitely larger than INT32_MAX
        // if value equals to INT32_MAX / 10, in order to make 
        // value*10 + last-digit <= INT32_MAX, last-digit must <= 7. 
        // INT32_MAX - (INT32_MAX/10)*10 = 7;
        if ((temp > max / 10) || (temp == max / 10 && remain > 7))
        {
            temp = 0;
            break;
        }

        // check if beyond the lower boundery, same idea as Max value. 
        // just the last-digit must >= -8.
        if ((min / 10 > temp) || (temp == min / 10 && remain < -8))
        {
            temp = 0;
            break;
        }

        temp = temp * 10 + remain;


        x /= 10;
    }


    return temp;
}