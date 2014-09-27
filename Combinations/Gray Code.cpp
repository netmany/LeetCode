/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        int s = 1 ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < s; j++) {
                v.push_back((1 << i) + v[s - 1 - j]);
            }
            s <<= 1;
        }
        return v;
    }
};
