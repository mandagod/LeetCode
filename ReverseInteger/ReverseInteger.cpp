/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Hide Tags Math

Author: mandagod Nov 07, 2014
*/


class Solution {
public:
    int reverse(int x) {
        int newX = 0;
        while (0 != x) {
            newX *= 10;
            newX += (x % 10);
            x /= 10;
        }
        
        return newX;
    }
};