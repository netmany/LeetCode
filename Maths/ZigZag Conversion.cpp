/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/


class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;
        int t = (nRows - 1) *2;
        vector<string> v(nRows,"");
        for(int i = 0; i < s.length(); i++){
            int j = i % t;
            if(j >= nRows) j = t -j;
            v[j] += string(1, s[i]);
        }
        string res;
        for(int i = 0; i < nRows; i++){
            res += v[i];
        }
        return res;
     }
};
