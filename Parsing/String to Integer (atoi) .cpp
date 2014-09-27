/*
Implement atoi to convert a string to an integer.
*/


class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL) return 0;
        int res = 0, p = 0;
        bool minus = false;
        while(str[p] == ' ') p++;
        if(str[p] == '-') { minus = true; p++;}
        else if(str[p] == '+') p++;
        while(str[p] == '0') p++;
        if(str[p] >= '1' && str[p] <= '9') { res = str[p] -'0'; p++;}
        long long  tmp = res;
        while(str[p] >= '0' && str[p] <= '9'){
            tmp = tmp * 10 + str[p] - '0'; p++;
            if(tmp >  INT_MAX) return minus ? INT_MIN : INT_MAX;
        }
        res = (int) tmp;
        return minus ? -res : res;
    }
};
