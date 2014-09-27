/*
Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        bool inv = false, minus = false; 
        double p = 1, pre = 0;
        if(n < 0) {inv = true; n = abs(n);}
        if(x < 0) {if(n & 1) minus = true; x = abs(x);}
        while(n-- && abs(pre - p) > 1e-20) {
            pre = p; p *= x;
        }
        if(inv) p = 1 / p;
        if(minus) p = -p;
        return p;
    }
};
