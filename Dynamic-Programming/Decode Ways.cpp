/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/


class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) {
            return '1' <= s[0] && s[0] <= '9' ? 1 : 0;
        }
        int fn, fn_1, t;
        fn = '1' <= s[s.length()-1] && s[s.length()-1] <= '9' ? 1 : 0;
        fn_1 = 1;
        for(int p = s.length() -2; p>= 0; p--){
            t = fn;
            fn = (('1' <= s[p] && s[p] <= '9' )? fn : 0) + 
                 ((s[p] == '1' && '0' <= s[p+1] && s[p+1] <= '9' || s[p] == '2' && '0' <= s[p+1] && s[p+1] <= '6') ? fn_1 : 0);
            fn_1 = t;
        }
        return fn;
    }
};
