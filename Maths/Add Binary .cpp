/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/


class Solution {
public:
    string addBinary(string a, string b) {
        string str; bool carry = false;
        int i = min(a.length(), b.length()) - 1;
        int ap = 0, bp = 0;
        if(a.length() > b.length()) ap = a.length() - b.length();
        else bp = b.length() - a.length();
        while(ap + i >= 0 || bp + i >= 0){
            int t = 0;
            if(ap + i >= 0 && a[ap + i] == '1') t++;
            if(bp + i >= 0 && b[bp + i] == '1') t++;
            if(carry) t++;
            switch(t){
                case 0: str = '0' + str; carry = false; break;
                case 1: str = '1' + str; carry = false; break;
                case 2: str = '0' + str; carry = true; break;
                case 3: str = '1' + str; carry = true; break;
            }
            i--;
        }
        if(carry) str = '1' + str;
        return str;
    }
};
