/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
    const char* d[3][9] = {{"I","II","III","IV","V","VI","VII","VIII","IX"},
                           {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                           {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}};
    const char* d3[3] = {"M","MM","MMM"};
public:
    string intToRoman(int num) {
        string res ="";
        int p = num / 1000;
        if(p > 0 && p < 4) res += d3[p-1];
        int i = 2, b = 100;
        while(b){
            p = (num % (10*b))/b;
            if(p) res += d[i][p-1];
            i--;
            b /= 10;
        }
        return res;
    }
};
