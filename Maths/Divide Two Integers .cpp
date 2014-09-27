/*
Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
    int div(int a, int b){
        if(a < b) return 0;
        if(a == b) return 1;
        int t = a, i = 1, res = 0;
        while(t >= b){
            while ((b << i) > 0 && t > (b << i)) {
                i++;
            }
            if(t == (b << i)) return res + (1<<i);
            t -= (b << (i - 1));
            res += 1 << (i-1); i = 1;
        }
        return res;
    }
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return 0;
        if(divisor == INT_MIN){
            return dividend == INT_MIN ? 1 : 0;
        }
        int offset = 0;
        if(dividend == INT_MIN){
            if(divisor > 0) {dividend += divisor; offset = -1;}
            else {dividend -= divisor; offset = 1;}
        }
        int a = abs(dividend), b = abs(divisor);
        bool minus = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        int res = div(a, b);
        return offset + (minus? -res : res);
    }
};
