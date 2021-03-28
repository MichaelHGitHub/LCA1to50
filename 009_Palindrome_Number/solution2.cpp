#include "header.h"

//
// We could build the reverse number(rx) of x and check if x == rx, but
// since there is a restrain on the length of x(int32), rx could
// overflow. So, we just build half of the reverse and check the second
// half equals the first half. 
bool isPalindrome2(int x)
{
    // Need to rule out the cases where 0 at the end of the number
    // for example: 100000
    if (x < 0 || (x != 0 && 0 == x % 10))
    {
        return false;
    }
    else if (x < 10)
    {
        return true;
    }

    int half = 0;

    while (x > half)
    {
        half = half * 10 + x % 10;
        x /= 10;
    }

    // For even number of digit, both half are equal, 
    // for odd number of digits, the newly build half is 10 times the
    // first half.
    return (x == half || x == half / 10);
}
