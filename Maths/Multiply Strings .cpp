/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int len = num1.length() + num2.length();
        string res(len,'1');
        int b1 = num1.length() - 1, b2 = num2.length() - 1;
        int b3 = len - 1, s, carry = 0;
        int i = 0, a, b;
        while(b3 + i >= 0) {
            s = 0;
            for(int j = 0; j <= -i; j++){
                a = b1 >= j ? (num1[b1 - j] - '0') : 0;
                b = b2 >= (- i - j) ? (num2[b2 + i + j] - '0') : 0;
                s += a * b;
            }
            s += carry;
            carry = s / 10; s = s % 10;
            res[b3 + i] = s + '0';
            i--;
        }
        if(res[0] == '0') res.erase(res.begin());
        return res;
        
    }
};
