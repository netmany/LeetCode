/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
    void query(char p, int* pri, int* v){
        switch(p){
            case 'I': case 'i': *pri = 0; *v = 1; break;
            case 'V': case 'v': *pri = 1; *v = 5; break;
            case 'X': case 'x': *pri = 2; *v = 10; break;
            case 'L': case 'l': *pri = 3; *v = 50; break;
            case 'C': case 'c': *pri = 4; *v = 100; break;
            case 'D': case 'd': *pri = 5; *v = 500; break;
            case 'M': case 'm': *pri = 6; *v = 1000; break;
        }
    }
    int val(char p, char q){
        int p_pri, pv, q_pri, qv;
        query(p, &p_pri, &pv);
        query(q, &q_pri, &qv);
        if (p_pri < q_pri)
            return - pv;
        else
            return pv;
    }
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0 ; i < s.size(); i ++){
            if (i+1 < s.size())
                sum += val(s[i], s[i+1]);
            else
                sum += val(s[i], s[i]);
        }
        return sum;
    }
};
