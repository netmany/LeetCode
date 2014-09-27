/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/


class Solution {
public:
    int reverse(int x) {
        int m = 0;
        do{
            m = m * 10 + x % 10;
            x /= 10;
        }while(x != 0);
        return m;
    }
};
